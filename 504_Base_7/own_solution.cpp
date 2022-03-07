class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string result = "";
        bool flag = num > 0? true : false;
        if (!flag) {
            num = -num;
        }
        while (num) {
            int residue = num % 7;
            result = to_string(residue) + result;
            num /= 7;
        }
        return flag? result : "-" + result;
    }
};