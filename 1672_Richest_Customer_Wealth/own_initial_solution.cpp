class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> assets;
        for (auto & account : accounts) {
            assets.push_back(accumulate(account.begin(), account.end(), 0));
        }
        return *max_element(assets.begin(), assets.end());
    }
};