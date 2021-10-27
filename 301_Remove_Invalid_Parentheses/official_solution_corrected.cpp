class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l_remove = 0, r_remove = 0;
        for (auto & ch : s) {
            if (ch == '(') {
                ++l_remove;
            } else if (ch == ')'){
                if (l_remove > 0) {
                    --l_remove;
                } else {
                    ++r_remove;
                }
            }
        }
        vector<string> result;
        backtrack(result, s, 0, 0, 0, l_remove, r_remove);
        return result;
    }
    void backtrack(vector<string>& result, string str, int start, int lcount, int rcount, int l_remove, int r_remove) {
        if (l_remove == 0 && r_remove == 0) {
            if (isValid(str)) {
                result.push_back(str);
            }
            return;
        }
        for (int i = start; i < str.size(); ++i) {
            if (i != start && str[i] == str[i - 1]) {
                if (str[i] == '(') {
                    ++lcount;
                } else if (str[i] == ')') {
                    ++rcount;
                }
                continue;
            }
            if (l_remove + r_remove > str.size() - i) {
                return;
            }
            if (str[i] == '(' && l_remove > 0) {
                backtrack(result, str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, l_remove - 1, r_remove);
            }
            if (str[i] == ')' && r_remove > 0) {
                backtrack(result, str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, l_remove, r_remove - 1);
            }
            if (str[i] == '(') {
                ++lcount;
            } else if (str[i] == ')') {
                ++rcount;
            }
            if (lcount < rcount) {
                break;
            }
        }
    }
    bool isValid(string str) {
        int count = 0;
        for (auto & ch : str) {
            if (ch == '(') {
                ++count;
            } else if (ch == ')') {
                --count;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
};