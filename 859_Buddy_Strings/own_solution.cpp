class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        unordered_map<char, int> map_s, map_goal;
        unordered_map<char, int>::iterator it;
        for (auto & ch : s) {
            ++map_s[ch];
        }
        for (auto & ch : goal) {
            ++map_goal[ch];
        }
        bool flag = false;
        for (it = map_s.begin(); it != map_s.end(); ++it) {
            if (it->second != map_goal[it->first]) {
                return false;
            }
            if (it->second > 1) {
                flag = true;
            }
        }
        if (s == goal && flag) {
            return true;
        }
        vector<int> not_equal_idx;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) {
                not_equal_idx.push_back(i);
            }
        }
        if (not_equal_idx.size() != 2) {
            return false;
        }
        if (s[not_equal_idx[0]] != goal[not_equal_idx[1]] || s[not_equal_idx[1]] != goal[not_equal_idx[0]]) {
            return false;
        }
        return true;
        
    }
};