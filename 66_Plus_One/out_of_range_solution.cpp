class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string num_str = "";
        for (int i = 0; i < digits.size(); ++i) {
            num_str += digits[i] + '0';
        }
        int num = stoi(num_str);
        ++num;
        num_str = to_string(num);
        vector<int> result;
        for (int i = 0; i < num_str.size(); ++i) {
            result.push_back(num_str[i] - '0');
        }
        return result;
    }   
};