class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> cache;
        return dfs(s, dict, cache);
    }

private:
    vector<string> dfs(
            const string& str,
            unordered_set<string>& dict,
            unordered_map<string, vector<string>>& cache) {

        if (str.empty()) {
            return {""};
        }

        if (cache.count(str) == 1) {
            return cache[str];
        }

        vector<string> ans;

        int len = str.length();
        for (int i = 1 ; i <= len ; ++i) {
            auto prefix = str.substr(0, i);
            if (dict.count(prefix) == 0) {
                continue;
            }

            auto suffix = str.substr(i, len - i);
            auto res = dfs(suffix, dict, cache);

            for (const auto& token : res) {
                auto word = token.empty() ? prefix : prefix + " " + token;
                ans.emplace_back(move(word));
            }
        }

        return cache[str] = ans;
    }
};