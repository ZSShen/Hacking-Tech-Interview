class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        /**
         *
         *      B--------C-------END
         *     /        /
         *    /        /
         *   A--------D
         *
         *   Upon visiting C, we should not remove it from the dictionary
         *   because that will lead to incomplete graph contruction.
         *
         *   Instead, we should maintain a map to keep the earlies discovery
         *   time for each node.
         */

        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, int> discovery;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        buildGraph(beginWord, endWord, dict, graph, discovery);
        if (discovery.count(endWord) == 0) {
            return {};
        }

        vector<string> config;
        config.emplace_back(beginWord);
        vector<vector<string>> ans;

        findAllPaths(0, beginWord, endWord, graph, discovery, config, ans);
        return ans;
    }

private:
    void buildGraph(
            const string& beginWord, const string& endWord,
            unordered_set<string>& dict,
            unordered_map<string, unordered_set<string>>& graph,
            unordered_map<string, int>& discovery) {

        discovery[beginWord] = 0;

        queue<string> q;
        q.emplace(beginWord);

        int time = 0;

        while (!q.empty()) {

            int n = q.size();
            ++time;

            for (int i = 0 ; i < n ; ++i) {
                auto src = q.front();
                q.pop();

                auto dst(src);
                int len = dst.length();
                for (int j = 0 ; j < len ; ++j) {
                    char backup = dst[j];

                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        dst[j] = ch;

                        if (dict.count(dst) == 0) {
                            continue;
                        }

                        // Add a new edge.
                        graph[src].emplace(dst);

                        // Update the discovery time for the new word.
                        if (discovery.count(dst) == 0) {
                            discovery[dst] = time;
                            q.emplace(dst);
                        }
                    }

                    dst[j] = backup;
                }
            }
        }
    }

    void findAllPaths(
            int time,
            const string& src, const string& end,
            unordered_map<string, unordered_set<string>>& graph,
            unordered_map<string, int>& discovery,
            vector<string>& config,
            vector<vector<string>>& ans) {

        if (src == end) {
            ans.emplace_back(config);
            return;
        }

        for (const auto& dst : graph[src]) {
            if (discovery[dst] != time + 1) {
                continue;
            }

            config.emplace_back(dst);
            findAllPaths(time + 1, dst, end, graph, discovery, config, ans);
            config.pop_back();
        }
    }
};