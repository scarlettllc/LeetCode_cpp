class Solution {
public:
    string toLowerCase(string s) {
        string result = "";
        for (auto & ch : s) {
            result += tolower(ch);
        }
        return result;
    }
};