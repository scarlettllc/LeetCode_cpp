class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> result;
        unordered_set<int>::iterator it;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            s.insert(i);
            for (auto & rich : richer) {
                int a = rich[0], b = rich[1];
                if (b == i) {
                    s.insert(a);
                } else if (s.find(a) == s.end() && s.find(b) != s.end()) {
                    s.insert(a);
                }
            }
            bool flag = true;
            while (flag) {
                bool flag1 = false;
                for (auto & rich : richer) {
                    int a = rich[0], b = rich[1];
                    if (s.find(a) == s.end() && s.find(b) != s.end()) {
                        s.insert(a);
                        flag1 = true;
                    }
                }
                flag = flag1;
            }
            int temp = i;
            for (it = s.begin(); it != s.end(); ++it) {
                if (quiet[*it] < quiet[temp]) {
                    temp = *it;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};