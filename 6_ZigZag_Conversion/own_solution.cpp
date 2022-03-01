class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<vector<char>> intermediate(numRows, vector<char>(s.size(), '-'));
        int k = 0;
        bool flag = true;
        for (int j = 0; j < s.size() && flag; j += (numRows - 1)) {
            for (int i = 0; i < numRows && flag; ++i) {
                intermediate[i][j] = s[k++];
                if (k == s.size()) {
                    flag = false;
                    break;
                }
            }
            for (int i = numRows - 2; i > 0 && flag; --i) {
                intermediate[i][j + numRows - i - 1] = s[k++];
                if (k == s.size()) {
                    flag = false;
                    break;
                }
            }
        }
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (intermediate[i][j] != '-') {
                    result.push_back(intermediate[i][j]);
                }
            }
        }
        return result;
    }
};