class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs, digit_logs;
        for (auto & log : logs) {
            if (isdigit(log[log.find(' ') + 1])) {
                digit_logs.push_back(log);
            } else {
                letter_logs.push_back(log);
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), [](const string& s1, const string& s2) {
            int pos1 = s1.find(' '), pos2 = s2.find(' ');
            string s1_first = s1.substr(0, pos1), s2_first = s2.substr(0, pos2);
            string s1_second = s1.substr(pos1 + 1), s2_second = s2.substr(pos2 + 1);
            return s1_second < s2_second || (s1_second == s2_second && s1_first < s2_first);
        });
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};