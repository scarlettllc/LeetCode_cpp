class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result = {};
        if (s.size() < p.size()) {
            return result;
        }
        unordered_map<char, int> golden;
        unordered_map<char, int> current;
        unordered_map<char, int>::iterator it;
        for (auto & ch : p) {
            ++golden[ch];
        }
        for (int i = 0; i < p.size(); ++i) {
            ++current[s[i]];
        }
        bool flag = true;
        for (it = current.begin(); it != current.end(); ++it) {
            if (golden[it->first] != current[it->first]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            result.push_back(0);
        }
        for (int i = p.size(); i < s.size(); ++i) {
            if (find(result.begin(), result.end(), i - p.size()) != result.end()) {
                if (s[i] != s[i - p.size()]) {
                    --current[s[i - p.size()]];
                    ++current[s[i]];
                    continue;
                } else {
                    result.push_back(i - p.size() + 1);
                    continue;
                }
            }
            --current[s[i - p.size()]];
            ++current[s[i]];
            flag = true;
            for (it = current.begin(); it != current.end();++it) {
                if (golden[it->first] != current[it->first]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(i - p.size() + 1);
            }
        }
        return result;
    }
};