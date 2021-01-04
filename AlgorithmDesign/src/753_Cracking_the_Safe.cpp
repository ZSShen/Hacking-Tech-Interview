class Solution {
public:
    string crackSafe(int n, int k) {

        /**
         *  Gradually append letters to the tail
         *  of the currennt input code for generating
         *  unique passwords.
         *
         *  e.g.: 4 seeds with lengnth 4.
         *
         *   a b c d
         *     b c d a
         *       c d a b
         *         d a b c
         *           a b c a
         *               ...
         */

        string pass(n, '0');
        string suffix(n - 1, '0');

        unordered_set<string> set;
        set.emplace(pass);

        int count = pow(k, n);
        dfs(n, k, count, set, pass, suffix);

        return pass;
    }

private:
    bool dfs(
            int n, int k,
            int count,
            unordered_set<string>& set,
            string& pass, string& prefix) {

        if (count == set.size()) {
            return true;
        }

        for (int i = 0 ; i < k ; ++i) {
            char ch = '0' + i;
            prefix.push_back(ch);

            if (set.count(prefix) == 1) {
                prefix.pop_back();
                continue;
            }

            pass.push_back(ch);
            auto suffix = prefix.substr(1, n - 1);
            set.emplace(prefix);

            bool res = dfs(n, k, count, set, pass, suffix);
            if (res) {
                return true;
            }

            set.erase(prefix);
            pass.pop_back();
            prefix.pop_back();
        }

        return false;
    }
};
