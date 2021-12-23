class Solution {
public:
    string longestDupSubstring(string s) {
        string result = "";
        for (int len = 1; len < s.size(); ++len) {
            set<string> candidates;
            for (int i = 0; i < s.size() - len + 1; ++i) {
                if (candidates.find(s.substr(i, len)) != candidates.end()) {
                    result = s.substr(i, len);
                } else {
                    candidates.insert(s.substr(i, len));
                }
            }
        }
        return result;
    }
};