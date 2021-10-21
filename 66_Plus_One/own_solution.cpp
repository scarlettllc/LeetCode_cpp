class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        bool flag = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (flag) {
                if (digits[i] != 9) {
                    result.insert(result.begin(), digits[i] + 1);
                    flag = false;
                } else {
                    result.insert(result.begin(), 0);
                }
            } else {
                result.insert(result.begin(), digits[i]);
            }
        }
        if (flag) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};