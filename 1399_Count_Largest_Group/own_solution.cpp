class Solution {
public:
    int count_str(string s) {
        int result = 0;
        for (auto & ch : s) {
            result += ch - '0';
        }
        return result;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            ++m[count_str(to_string(i))];
        }
        unordered_map<int, int>::iterator it;
        int max_count = 0;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > max_count) {
                max_count = it->second;
            }
        }
        int result = 0;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second == max_count) {
                ++result;
            }
        }
        return result;
    }
};