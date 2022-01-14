bool compare(const vector<int> & a, const vector<int>& b) {
    return a[0] + a[1] < b[0] + b[1];
}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        for (auto & num1 : nums1) {
            for (auto & num2 : nums2) {
                result.push_back({num1, num2});
            }
        }
        sort(result.begin(), result.end(), compare);
        k = min(k, int(result.size()));
        return vector<vector<int>>({result.begin(), result.begin() + k});
    }
};