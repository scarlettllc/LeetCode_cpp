class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = 0, x = 0, y = 0;
        for (x = 0; x < n; ++x) {
            if (x == 0 || nums[x] != nums[x - 1]) {
                while (y < n && (nums[y] < nums[x] + k || y <= x)) {
                    ++y;
                }
                if (y < n && nums[y] == nums[x] + k) {
                    ++result;
                }
            }
        }
        return result;
    }
};