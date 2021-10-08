class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return {};
        }
        vector<string> result;
        for (int i = 0; i <= s.size() - 10; ++i) {
            string pattern = s.substr(i, 10);
            for (int j = i + 1; j <= s.size() - 10; ++j) {
                bool flag = true;
                for (int k = 0; k < 10; ++k) {
                    if (s[j + k] != pattern[k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (find(result.begin(), result.end(), pattern) == result.end()) {
                        result.emplace_back(pattern);
                    }
                    break;
                }
            }
        }
        return result;
    }
};