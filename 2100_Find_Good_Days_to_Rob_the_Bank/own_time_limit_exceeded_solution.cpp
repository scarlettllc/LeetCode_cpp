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
        for (int i = time; i < n - time; ++i) {
            bool flag = true;
            for (int j = i; j > i - time; --j) {
                if (security[j] > security[j - 1]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            for (int j = i; j < i + time; ++j) {
                if (security[j] > security[j + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(i);
            }
        }
        return result;
    }
};