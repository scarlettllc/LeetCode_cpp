class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (auto & account : accounts) {
            result = max(result, accumulate(account.begin(), account.end(), 0));
        }
        return result;
    }
};