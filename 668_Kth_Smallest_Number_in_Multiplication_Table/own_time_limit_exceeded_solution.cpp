class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                nums.push_back(i * j);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};