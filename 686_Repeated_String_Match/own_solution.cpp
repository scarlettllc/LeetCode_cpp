class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a.find(b) != a.npos) {
            return 1;
        }
        int result = 0, last_pos = -1;
        while (b.find(a, 0) != b.npos) {
            int pos = b.find(a, 0);
            if (last_pos != -1 && pos != last_pos) {
                return -1;
            }
            b = b.substr(0, pos) + b.substr(pos + a.size());
            ++result;
            last_pos = pos;
        }
        if (b.size() == 0) {
            return result;
        }
        for (int i = 0; i < b.size(); ++i) {
            if (a.find(b[i], 0) == a.npos) {
                return -1;
            }
        }
        for (int i = 0; i <= min(a.size(), b.size()); ++i) {
            if (a.substr(a.size() - i) == b.substr(0, i) && a.substr(0, b.size() - i) == b.substr(i)) {
                if (i == 0 || i == min(a.size(), b.size())) {
                    return (result + 1);
                } else {
                    return (result + 2);
                }
            }
        }
        return -1;
    }
};