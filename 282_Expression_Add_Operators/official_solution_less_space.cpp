class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expr = "";
        backtrack(ans, num, target, expr, 0, 0, 0);
        return ans;
    }
    void backtrack(vector<string> &ans, string num, int target, string &expr, int i, long int res, long int mul) {
        if (i == num.size()) {
            if (res == target) {
                ans.push_back(expr);
            }
            return;
        }
        int expr_sz = expr.size();
        if (i != 0) {
            expr.push_back('0');
        }
        long int val = 0;
        for (int j = i; j < num.size() && (j == i || num[i] != '0'); ++j) {
            val = val * 10 + num[j] - '0';
            expr.push_back(num[j]);
            if (i == 0) {
                backtrack(ans, num, target, expr, j + 1, val, val);
            } else{
                expr[expr_sz] = '+'; backtrack(ans, num, target, expr, j + 1, res + val, val);
                expr[expr_sz] = '-'; backtrack(ans, num, target, expr, j + 1, res - val, -val);
                expr[expr_sz] = '*'; backtrack(ans, num, target, expr, j + 1, res - mul + mul * val, mul * val);
            }
        }
        expr.resize(expr_sz);
    }
};