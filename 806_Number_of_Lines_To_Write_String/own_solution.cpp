class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum = 0, rows = 0;
        for (auto & ch : s) {
            sum += widths[ch - 'a'];
            if (sum > 100) {
                ++rows;
                sum = widths[ch - 'a'];
            }
        }
        return {rows + 1, sum};
    }
};