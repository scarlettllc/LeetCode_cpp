class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0, n = ages.size();
        vector<int> cnt(121, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[ages[i]];
        }
        vector<int> pre(121, 0);
        for (int i = 1; i <= 120; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        for (int i = 15; i <= 120; ++i) {
            if (cnt[i]) {
                result += (cnt[i] * (pre[i] - pre[i * 0.5 + 7] - 1));
            }
        }
        return result;
    }
};