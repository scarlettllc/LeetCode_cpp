class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<string> binaries;
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            binaries.push_back(decimal_to_binary(data[i]));
        }
        int i = 0;
        while (i < n) {
            string temp = binaries[i];
            if (temp[0] == '1' && temp[1] == '0') {
                return false;
            }
            int len = 0;
            while (temp[len] == '1') {
                ++len;
            }
            if (len > 4) {
                return false;
            }
            for (int j = i + 1; j < i + len; ++j) {
                if (j >= n) {
                    return false;
                }
                if (binaries[j][0] != '1' || binaries[j][1] != '0') {
                    return false;
                }
            }
            if (len != 0) {
                i = i + len;
            } else {
                ++i;
            }
        }
        return true;
    }
    string decimal_to_binary(int decimal) {
        string result = "";
        while (decimal) {
            result = to_string(decimal % 2) + result;
            decimal /= 2;
        }
        if (result.size() < 8) {
            string complement(8 - result.size(), '0');
            result = complement + result;
        }
        return result;
    }
};