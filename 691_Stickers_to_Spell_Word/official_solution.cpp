class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        vector<int> dp((1 << m), -1);
        dp[0] = 0;
        int result = helper((1 << m) - 1, m, target, dp, stickers);
        return result > m ? -1 : result;
    }
    int helper(int mask, int m, string target, vector<int>& dp, vector<string>& stickers) {
        if (dp[mask] != -1) {
            return dp[mask];
        }
        dp[mask] = m + 1;
        for (auto & sticker : stickers) {
            int left = mask;
            vector<int> c(26, 0);
            for (auto & ch : sticker) {
                ++c[ch - 'a'];
            }
            for (int i = 0; i < m; ++i) {
                if (((mask >> i) & 1) && c[target[i] - 'a'] > 0) {
                    --c[target[i] - 'a'];
                    left ^= (1 << i);
                }
            }
            if (left < mask) {
                dp[mask] = min(dp[mask], helper(left, m, target, dp, stickers) + 1);
            }
        }
        return dp[mask];
    }
};