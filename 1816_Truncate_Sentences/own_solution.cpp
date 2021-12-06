class Solution {
public:
    string truncateSentence(string s, int k) {
        string result = "";
        int i = 0, count = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                result += s[i];
            } else {
                ++count;
                if (count == k) {
                    break;
                } else {
                    result += ' ';
                }
            }
            ++i;
        }
        return result;
    }
};