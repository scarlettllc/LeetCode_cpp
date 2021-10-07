class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                ++result;
            }
            char c = s[i];
            while (i < s.size() && s[i] != ' ') {
                c = s[i];
                ++i;
            }
            ++i;
        }
        return result;
    }
};