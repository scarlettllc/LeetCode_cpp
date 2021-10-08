class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> result;
        int n = s.size();
        for (int i = 0; i <= n - 10; ++i) {
            string pattern = s.substr(i, 10);
            if (++cnt[pattern] == 2) {
                result.emplace_back(pattern);
            }
        }
        return result;
    }
};