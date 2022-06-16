class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> result;
        unordered_set<int> visited;
        for (auto & num : nums) {
            if (visited.count(num - k)) {
                result.insert(num - k);
            }
            if (visited.count(num + k)) {
                result.insert(num);
            }
            visited.insert(num);
        }
        return result.size();
    }
};