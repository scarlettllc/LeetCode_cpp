class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (auto & account : accounts) {
            int temp = accumulate(account.begin(), account.end(), 0);
            if(temp > result) {
                result = temp;
            }
        }
        return result;
    }
};