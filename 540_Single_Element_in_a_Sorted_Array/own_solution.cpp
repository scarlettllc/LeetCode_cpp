class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto & num : nums) {
            if (s.count(num)) {
                s.erase(num);
            } else {
                s.insert(num);
            }
        }
        return *s.begin();
    }
};