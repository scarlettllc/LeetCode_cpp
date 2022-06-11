class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0, dp0New, dp1New;
        for (auto & c : s) {
            dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                ++dp0New;
            } else {
                ++dp1New;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};