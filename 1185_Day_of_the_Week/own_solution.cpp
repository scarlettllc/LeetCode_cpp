class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int count = 4;
        for (int i = 1971; i < year; ++i) {
            if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)) {
                count += 366;
            } else {
                count += 365;
            }
        }
        vector<int> months{31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i = 1; i < month; ++i) {
            count += months[i - 1];
        }
        if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && month > 2) {
            ++count;
        }
        count += day;
        vector<string> week{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return week[count % 7];
    }
};