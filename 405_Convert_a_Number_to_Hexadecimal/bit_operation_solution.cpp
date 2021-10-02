class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string result = "";
        for (int i = 7; i >= 0; --i) {
            int val = (num >> (4 * i)) & 0xf;
            if (result.size() > 0 || val) {
                result += val < 10? char(val + '0') : char('a' + val - 10);
            }
        }
        return result;
    }
};