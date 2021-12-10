class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> count_license(26, 0);
        int n = licensePlate.size();
        for (int i = 0; i < n; ++i) {
            if (isalpha(licensePlate[i])) {
                ++count_license[tolower(licensePlate[i]) - 'a'];
            }
        }
        int minLen = INT_MAX;
        string result;
        int m = words.size();
        for (int j = 0; j < m; ++j) {
            int len = words[j].size();
            vector<int> temp_count(26, 0);
            for (int i = 0; i < len; ++i) {
                ++temp_count[words[j][i] - 'a'];
            }
            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (temp_count[i] < count_license[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (len < minLen) {
                    minLen = len;
                    result = words[j];
                }
            }
        }
        return result;
    }
};