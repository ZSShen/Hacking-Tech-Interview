class Solution {
public:
    string addStrings(string num1, string num2) {


        int len_1 = num1.length();
        int len_2 = num2.length();

        string res(max(len_1, len_2) + 1, 0);

        int i = len_1 - 1;
        int j = len_2 - 1;
        int k = 0;

        while (i >= 0 || j >= 0) {
            int op1 = (i >= 0) ? num1[i] - '0' : 0;
            int op2 = (j >= 0) ? num2[j] - '0' : 0;

            res[k] += op1 + op2;
            if (res[k] > 9) {
                res[k] -= 10;
                ++res[k + 1];
            }

            --i;
            --j;
            ++k;
        }

        while (!res.empty() && res.back() == 0) {
            res.pop_back();
        }
        for (char& c : res) {
            c += '0';
        }

        reverse(res.begin(), res.end());
        return res.empty() ? "0" :  res;
    }
};