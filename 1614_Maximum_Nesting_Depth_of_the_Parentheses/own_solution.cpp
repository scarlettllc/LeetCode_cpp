class Solution {
public:
    int maxDepth(string s) {
        int result = 0, count = 0;
        for (auto & ch : s) {
            if (ch == '(') {
                ++count;
                result = max(result, count);
            } else if (ch == ')'){
                --count;
            }
        }
        return result;
    }
};