class Solution {
public:
    int dayOfYear(string date) {
        vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2)) - 1;
        int result = stoi(date.substr(8, 2));
        for (int i = 0; i < month; ++i) {
            result += months[i];
        }
        if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month >= 2) {
            ++result;
        }
        return result;
    }
};