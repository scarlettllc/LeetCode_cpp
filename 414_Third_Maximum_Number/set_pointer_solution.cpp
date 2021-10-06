class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() >= 3? *(------s.end()) : *(--s.end());
    }
};