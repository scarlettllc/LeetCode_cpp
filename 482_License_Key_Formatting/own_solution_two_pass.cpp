class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string passwords = "";
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '-') {
                continue;
            } else if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {
                passwords += s[i];
            } else {
                passwords += char(s[i] - 'a' + 'A');
            }
        }
        string result = "";
        int groups = passwords.size() / k;
        int remainder = passwords.size() % k;
        if (remainder != 0) {            
            result += passwords.substr(0, remainder);
            result += '-';            
        }
        for (int i = remainder; i < passwords.size(); i += k) {
            result += passwords.substr(i, k);
            result += '-';
        }
        result = result.substr(0, result.size() - 1);
        return result;
    }
};