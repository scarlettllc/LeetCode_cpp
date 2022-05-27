class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for (auto & c : s) {
            if (c == ')') {
                --level;
            } 
            if (level) {
                result += c;
            }
            if (c == '(') {
                ++level;
            }
        }
        return result;
    }
};