class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for (auto & num : nums) {
            if (!s.count(num)) {
                s.insert(num);
            } else {
                return num;
            }
        }
        return 0;
    }
};