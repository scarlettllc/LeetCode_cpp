class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters = "";
        string not_letters = "";
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                letters += ch;
                s[i] = 'a';
            } else {
                not_letters += ch;
            }
        }
        reverse(letters.begin(), letters.end());
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                s[i] = letters[j];
                ++j;
            }
        }
        return s;
    }
};