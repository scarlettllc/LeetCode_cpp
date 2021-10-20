class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums[0], n = nums.size();
        if (n == 1) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] - min);
        }
        return sum;
    }
};