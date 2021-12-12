class Solution {
public:
    string toLowerCase(string s) {
        string result = "";
        for (auto & ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                result += 'a' + ch - 'A';
            } else {
                result += ch;
            }
        }
        return result;
    }
};