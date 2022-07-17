class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            while (nums[i] < n) {
                int num = nums[i];
                nums[i] = n;
                i = num;
                ++count;
            }
            result = max(result, count);
        }
        return result;
    }
};