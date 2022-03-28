class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> binaries;
        while (n) {
            binaries.push_back(n % 2);
            n /= 2;
        }
        for (int i = 1; i < binaries.size(); ++i) {
            if (binaries[i] == binaries[i - 1]) {
                return false;
            }
        }
        return true;
    }
};