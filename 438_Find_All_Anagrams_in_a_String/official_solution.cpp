class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if (slen < plen) {
            return vector<int>();
        }
        vector<int> result;
        vector<int> count(26, 0);
        for (int i = 0; i < plen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        int differ = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                ++differ;
            }
        }
        if (differ == 0) {
            result.push_back(0);
        }
        for (int i = 0; i < slen - plen; ++i) {
            if (count[s[i] - 'a'] == 1) {
                --differ;
            } else if (count[s[i] - 'a'] == 0) {
                ++differ;
            }
            --count[s[i] - 'a'];
            if (count[s[i + plen] - 'a'] == -1) {
                --differ;
            } else if (count[s[i + plen] - 'a'] == 0) {
                ++differ;
            }
            ++count[s[i + plen] - 'a'];
            if (differ == 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};