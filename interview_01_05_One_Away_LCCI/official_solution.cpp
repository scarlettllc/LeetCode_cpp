class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if (m - n == 1) {
            return helper(second, first);
        } else if (n - m == 1) {
            return helper(first, second);
        } else if (m == n) {
            bool different = false;
            for (int i = 0; i < m; ++i) {
                if (first[i] != second[i]) {
                    if (different) {
                        return false;
                    } else {
                        different = true;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }
    bool helper(string shorter, string longer) {
        int i = 0, j = 0, m = shorter.size(), n = longer.size();
        while (i < m && j < n) {
            if (shorter[i] == longer[j]) {
                ++i;
            }
            ++j;
            if (abs(j - i) > 1) {
                return false;
            }
        }
        return true;
    }
};