class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (auto & email : emails) {
            int pos = email.find('@');
            string domain = email.substr(pos + 1);
            string local = email.substr(0, pos);
            int pos2 = local.find('+');
            if (pos2 != string::npos) {
                local = local.substr(0, pos2);
            }
            string true_local = "";
            for (auto & c : local) {
                if (c != '.') {
                    true_local += c;
                }
            }
            s.insert(true_local + '@' + domain);
        }
        return s.size();
    }
};