class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, int> indeg;
        for (const auto& word : words) {
            for (char c : word) {
                indeg[c] = 0;
            }
        }

        unordered_map<char, unordered_set<char>> graph;
        int n = words.size();
        for (int i = 1 ; i < n ; ++i) {
            const auto& src = words[i - 1];
            const auto& dst = words[i];

            int ls = src.length();
            int ld = dst.length();

            bool has_diff = false;

            int j = 0, k = 0;
            while (j < ls && k < ld) {
                char s = src[j];
                char d = dst[k];

                if (s != d) {
                    if (graph[s].count(d) == 0) {
                        graph[s].emplace(d);
                        ++indeg[d];
                    }
                    has_diff = true;
                    break;
                }

                ++j;
                ++k;
            }

            // zyab
            // zya  => can not find the predecessor for b.
            if (!has_diff && ls > ld) {
                return "";
            }
        }

        queue<char> q;
        for (const auto& pair : indeg) {
            if (pair.second == 0) {
                q.emplace(pair.first);
            }
        }

        string order;

        while (!q.empty()) {
            char s = q.front();
            q.pop();

            order.push_back(s);

            for (char d : graph[s]) {
                --indeg[d];
                if (indeg[d] == 0) {
                    q.emplace(d);
                }
            }
        }

        return order.length() == indeg.size() ? order : "";
    }
};