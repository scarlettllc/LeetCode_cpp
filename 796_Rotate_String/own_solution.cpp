class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s.substr(0, i + 1) == goal.substr(n - i - 1, i + 1) && s.substr(i + 1) == goal.substr(0, n - i - 1)) {
                return true;
            }
        }
        return false;
    }
};