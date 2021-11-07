class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return m * n;
        }
        int min_a = ops[0][0], min_b = ops[0][1];
        for (auto & a_b : ops) {
            int temp_a = a_b[0];
            int temp_b = a_b[1];
            if (temp_a < min_a) {
                min_a = temp_a;
            }
            if (temp_b < min_b) {
                min_b = temp_b;
            }
        }
        return min_a * min_b;
    }
};