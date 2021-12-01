class Solution {
public:
    int maxPower(string s) {
        int result = 0, i = 0, j = 0, n = s.size();
        while (i < s.size()) {
            j = i;
            while (j + 1 < n && s[j + 1] == s[i]) {
                ++j;
            }
            result = max(result, j - i + 1);
            i = j + 1;
        }
        return result;
    }
};