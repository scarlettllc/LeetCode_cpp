class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (n + m) * mean;
        int curr_total = accumulate(rolls.begin(), rolls.end(), 0);
        int complement_sum = total - curr_total;
        if (complement_sum > n * 6 || complement_sum < n * 1) {
            return {};
        }
        int base = complement_sum / n;
        vector<int> result(n, base);
        int redundant = complement_sum % n;
        for (int i = 0; i < redundant; ++i) {
            ++result[i];
        }
        return result;
    }
};