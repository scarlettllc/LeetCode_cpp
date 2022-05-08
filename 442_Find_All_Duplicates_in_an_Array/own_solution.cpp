class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> s;
        for (auto & num : nums) {
            if (!s.count(num)) {
                s.insert(num);
            } else {
                result.push_back(num);
            }
        }
        return result;
    }
};