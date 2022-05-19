class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), result = 0;
        for (auto & num : nums) {
            result += abs(num - x);
        }
        return result;
    }
    int quickSelect(vector<int>& nums, int left, int right, int index) {
        int q = randomPartition(nums, left, right);
        if (q == index) {
            return nums[q];
        } else {
            return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
        }
    }
    int randomPartition(vector<int>& nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        i = left - 1;
        for (int j = left; j < right; ++j) {
            if (nums[j] < nums[right]) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
};