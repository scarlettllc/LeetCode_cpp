class Solution {
public:
    string countAndSay(int n) {
        vector<string> strs;
        strs.push_back("0");
        strs.push_back("1");
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            string prev = strs[i - 1];
            int j = 0;
            while (j < prev.size()) {
                int count = 1;
                int k = j + 1;
                for (; k < prev.size(); ++k) {
                    if (prev[k] == prev[k - 1]) {
                        ++count;
                    } else {
                        break;
                    }
                }
                temp += to_string(count);
                temp += prev[j];
                j = k;
            }
            strs.push_back(temp);
        }
        return strs[n];
    }
};