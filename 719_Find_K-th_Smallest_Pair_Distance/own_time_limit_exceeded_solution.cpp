class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> distances;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                distances.push_back(abs(nums[i] - nums[j]));
            }
        }
        sort(distances.begin(), distances.end());
        return distances[k - 1];
    }
};