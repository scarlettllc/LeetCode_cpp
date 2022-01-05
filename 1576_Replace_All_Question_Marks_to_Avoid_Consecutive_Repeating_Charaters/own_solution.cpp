class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        vector<char> candidates{'a', 'b', 'c', 'd', 'e', 
        'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (int j = 0; j < 26; ++j) {
                    if ((i == 0 || (i > 0 && s[i - 1] != candidates[j])) && (i == n - 1 || (i < n - 1 && s[i + 1] != candidates[j]))) {
                        s[i] = candidates[j];
                        break;
                    }
                }
            }
        }
        return s;
    }
};