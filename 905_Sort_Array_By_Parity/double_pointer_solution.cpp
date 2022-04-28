class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                result[left++] = nums[i];
            } else {
                result[right--] = nums[i];
            }
        }
        return result;
    }
};