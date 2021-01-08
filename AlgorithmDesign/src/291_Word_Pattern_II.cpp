class Solution {
public:
    bool wordPatternMatch(string pat, string str) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        return dfs(pat, 0, pat.length(), str, 0, str.length(), map, set);
    }

private:
    bool dfs(
            const string& pat, int idx_p, int end_p,
            const string& str, int idx_s, int end_s,
            unordered_map<char, string>& map,
            unordered_set<string>& set) {

        if (idx_p == end_p && idx_s == end_s) {
            return true;
        }

        if (idx_p == end_p || idx_s == end_s) {
            return false;
        }

        char ch = pat[idx_p];

        if (map.count(ch) == 1) {
            // The letter has been mapped.
            const auto& token = map[ch];

            int len = token.length();
            if (idx_s + len > end_s) {
                return false;
            }

            auto prefix = str.substr(idx_s, len);
            if (token != prefix) {
                return false;
            }

            bool res = dfs(
                pat, idx_p + 1, end_p, str, idx_s + len, end_s, map, set);
            if (res) {
                return true;
            }
        } else {
            int range = end_s - idx_s;

            for (int i = 1 ; i <= range ; ++i) {
                auto token = str.substr(idx_s, i);
                if (set.count(token) == 1) {
                    continue;
                }

                set.emplace(token);
                map[ch] = token;

                bool res = dfs(
                    pat, idx_p + 1, end_p, str, idx_s + i, end_s, map, set);
                if (res) {
                    return true;
                }

                map.erase(ch);
                set.erase(token);
            }
        }

        return false;
    }
};