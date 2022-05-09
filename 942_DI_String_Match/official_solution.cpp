class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(), low = 0, high = n;
        vector<int> perm(n + 1);
        for (int i = 0; i < n; ++i) {
            perm[i] = (s[i] == 'I' ? low++ : high--);
        }
        perm[n] = low;
        return perm;
    }
};