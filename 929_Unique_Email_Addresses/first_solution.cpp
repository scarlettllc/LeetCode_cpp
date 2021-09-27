class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        int n = emails.size();
        for (int i = 0; i < n; ++i) {
            string email = emails[i];
            int pos = 0;
            while (pos < email.size()) {
                if (email[pos] == '@') {
                    break;
                }
                ++pos;
            }
            string right_part = email.substr(pos);
            string left_part = email.substr(0, pos);
            pos = -1;
            for (int j = 0; j < left_part.size(); ++j) {
                if (email[j] == '+') {
                    pos = j;
                    break;
                }
            }
            if (pos != -1) {
                left_part = left_part.substr(0, pos);
            }
            string final_left_part = "";
            for (int j = 0; j < left_part.size(); ++j) {
                if (left_part[j] != '.') {
                    final_left_part += left_part[j];
                }
            }
            string equal_email = final_left_part + right_part;
            if (!s.count(equal_email)) {
                s.insert(equal_email);
            }
        }
        return s.size();
    }
};

// Runtime: 32 ms, faster than 37.46% of C++ online submissions for Unique Email Addresses.
// Memory Usage: 16.3 MB, less than 13.51% of C++ online submissions for Unique Email Addresses.