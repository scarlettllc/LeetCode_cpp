class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> result;
        int n = security.size();
        if (time == 0) {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
            return result;
        }
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }
        for (int i = time; i < n - time; ++i) {
            if (left[i] >= time && right[i] >= time) {
                result.push_back(i);
            }
        }
        return result;
    }
};