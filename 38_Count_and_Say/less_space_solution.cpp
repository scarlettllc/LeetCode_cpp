class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string temp;
        for (int i = 2; i <= n; ++i) {
            temp = "";
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
            prev = temp;
        }
        return prev;
    }
};