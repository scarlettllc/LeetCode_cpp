class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3, 0);
        for (auto & stone : stones) {
            ++count[stone % 3]; 
        }   
        if (count[0] % 2 == 0) {
            return count[1] >= 1 && count[2] >= 1;
        } else {
            return abs(count[1] - count[2]) > 2;
        }
    }
};