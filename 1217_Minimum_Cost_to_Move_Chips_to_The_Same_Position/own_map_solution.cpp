class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int, int> m;
        for (auto & pos : position) {
            ++m[pos];
        }
        int odd = 0, even = 0;
        for (auto & [p, freq] : m) {
            if (p % 2 == 0) {
                even += freq;
            } else {
                odd += freq;
            }
        }
        return odd > even ? even : odd;
    }
};