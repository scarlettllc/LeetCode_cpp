class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        while (true) {
            int x = rand() % nums.size(), y = rand() % nums.size();
            if (x != y && nums[x] == nums[y]) {
                return nums[x];
            }
        }
        return -1;
    }
};