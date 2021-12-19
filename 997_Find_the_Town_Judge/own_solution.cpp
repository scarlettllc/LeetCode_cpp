class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> candidates;
        for (int i = 1; i <= n; ++i) {
            candidates.insert(i);
        }
        for (int i = 0; i < trust.size(); ++i) {
            candidates.erase(trust[i][0]);
        }
        if (candidates.empty()) {
            return -1;
        }
        if (candidates.size() > 1) {
            return -1;
        }
        int candidate = *candidates.begin();
        vector<bool> flags(n + 1, false);
        for (int i = 0; i < trust.size(); ++i) {
            if (trust[i][1] == candidate) {
                flags[trust[i][0]] = true;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (i != candidate && flags[i] == false) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return candidate;
        } else {
            return -1;
        }
    }
};