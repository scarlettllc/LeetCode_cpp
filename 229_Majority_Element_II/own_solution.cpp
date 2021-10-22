class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        vector<int> result;
        unordered_map<int,int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > k) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};