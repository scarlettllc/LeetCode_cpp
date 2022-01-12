class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, mid = INT_MAX;
        for (auto & num : nums) {
            if (num <= small) {
                small = num;
            } else if (num <= mid) {
                mid = num;
            } else {
                return true;
            }
        }
        return false;
    }
};