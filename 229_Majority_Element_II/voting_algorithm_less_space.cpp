class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote1 = 0, vote2 = 0, element1, element2;
        for (auto num : nums) {
            if (vote1 > 0 && num == element1) {
                ++vote1;
            } else if (vote2 > 0 && num == element2) {
                ++vote2;
            } else if (vote1 == 0) {
                element1 = num;
                ++vote1;
            } else if (vote2 == 0) {
                element2 = num;
                ++vote2;
            } else {
                --vote1;
                --vote2;
            }
        }
        vote1 = 0; vote2 = 0;
        for (auto num : nums) {
            if (num == element1) {
                ++vote1;
            } else if (num == element2) {
                ++vote2;
            }
        }
        vector<int> result;
        if (vote1 > nums.size() / 3) {
            result.push_back(element1);
        }
        if (vote2 > nums.size() / 3) {
            result.push_back(element2);
        }
        return result;
    }
};