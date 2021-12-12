class Solution {
public:
    string toLowerCase(string s) {
        for (auto & ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch |= 32;
            } 
        }
        return s;
    }
};