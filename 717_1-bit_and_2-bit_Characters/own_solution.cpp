class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n) {
            if (bits[i] == 1) {
                i += 2;
                if (i == n) {
                    return false;
                }
            } else {
                ++i;
                if (i == n) {
                    return true;
                }
            }
        }
        return false;
    }
};