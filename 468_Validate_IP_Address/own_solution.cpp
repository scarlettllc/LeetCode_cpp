class Solution {
public:
    string validIPAddress(string queryIP) {
        vector<string> addresses;
        int i = 0, n = queryIP.size();
        if (queryIP.find('.') != string::npos) {
            if (queryIP[0] == '.' || queryIP[n - 1] == '.') {
                return "Neither";
            }
            while (i < n) {
                int j = i;
                while (j < n && queryIP[j] != '.') {
                    ++j;
                }
                addresses.push_back(queryIP.substr(i, j - i));
                i = j + 1;
            }
            if (addresses.size() != 4) {
                return "Neither";
            }
            for (int k = 0; k < 4; ++k) {
                for (int p = 0; p < addresses[k].size(); ++p) {
                    if (addresses[k][p] < '0' || addresses[k][p] > '9') {
                        return "Neither";
                    }
                }
                if (addresses[k].size() == 0 || addresses[k].size() > 3 || stoi(addresses[k]) < 0 || stoi(addresses[k]) > 255) {
                    return "Neither";
                }
                if (stoi(addresses[k]) != 0 && addresses[k][0] == '0') {
                    return "Neither";
                }
                if (stoi(addresses[k]) == 0 && addresses[k].size() > 1) {
                    return "Neither";
                }


            }
            return "IPv4";
        } else if (queryIP.find(':') != string::npos) {
            if (queryIP[0] == ':' || queryIP[n - 1] == ':') {
                return "Neither";
            }
            while (i < n) {
                int j = i;
                while (j < n && queryIP[j] != ':') {
                    ++j;
                }
                addresses.push_back(queryIP.substr(i, j - i));
                i = j + 1;
            }
            if (addresses.size() != 8) {
                return "Neither";
            }   
            for (int k = 0; k < 8; ++k) {
                if (addresses[k].size() == 0 || addresses[k].size() > 4) {
                    return "Neither";
                }
                for (int p = 0; p < addresses[k].size(); ++p) {
                    if ((addresses[k][p] >= '0' && addresses[k][p] <= '9') || 
                    (addresses[k][p] >= 'a' && addresses[k][p] <= 'f') || 
                    (addresses[k][p] >= 'A' && addresses[k][p] <= 'F')) {
                        continue;
                    } else {
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};