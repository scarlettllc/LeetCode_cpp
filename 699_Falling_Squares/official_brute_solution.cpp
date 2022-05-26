class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n, 0);
        for (int i = 0; i < n; ++i) {
            heights[i] = positions[i][1];
            int left1 = positions[i][0], right1 = left1 + heights[i] - 1;
            for (int j = 0; j < i; ++j) {
                int left2 = positions[j][0], right2 = left2 + positions[j][1] - 1;
                if (right2 >= left1 && left2 <= right1) {
                    heights[i] = max(heights[i], heights[j] + positions[i][1]);
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            heights[i] = max(heights[i], heights[i - 1]);
        }
        return heights;
    }
};