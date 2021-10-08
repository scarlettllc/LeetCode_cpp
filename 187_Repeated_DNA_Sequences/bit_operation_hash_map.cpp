class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> bin{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> cnt;
        vector<string> result;
        int x = 0; 
        for (int i = 0; i < 9; ++i) {
            x = (x << 2) | bin[s[i]];
        }
        int n = s.size();
        for (int i = 0; i <= n - 10; ++i) {
            x = (x << 2 | bin[s[i + 9]]) & ((1 << 20) - 1);
            if (++cnt[x] == 2) {
                result.emplace_back(s.substr(i, 10));
            }
        }
        return result;
    }
};