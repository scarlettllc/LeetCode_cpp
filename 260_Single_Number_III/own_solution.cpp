class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> m;
        for (auto & num : nums) {
            ++m[num];
        }
        unordered_map<int, int>::iterator it;
        for(it = m.begin(); it!= m.end(); ++it) {
            if (it->second == 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};