class Solution {
public:
    string longestDupSubstring(string s) {
        map<string, int> m;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 1; j < s.size() - i + 1; ++j) {
                string candidate = s.substr(i, j);
                if (m.find(candidate) != m.end()) {
                    continue;
                }
                for (int k = 0; k < s.size() - j + 1; ++k) {
                    if (s.substr(k, j) == candidate) {
                        ++m[candidate];
                    }
                }
            }
        }
        string result = "";
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1 && it->first.size() > result.size()) {
                result = it->first;
            }
        }
        return result;
    }
};