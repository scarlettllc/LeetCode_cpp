class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<vector<int>> list;
        return dfs(0, num, num.size(), list);
    }
    bool dfs(int u, string num, int n, vector<vector<int>>& list) {
        int m = list.size();
        if (u == n) {
            return m >= 3;
        }
        int max = num[u] == '0' ? (u + 1) : n;
        vector<int> cur;
        for (int i = u; i < max; ++i) {
            cur.insert(cur.begin(), num[i] - '0');
            if (m < 2 || check(list[m - 2], list[m - 1], cur)) {
                list.push_back(cur);
                if (dfs(i + 1, num, n, list)) {
                    return true;
                }
                list.pop_back();
            }
        }
        return false;
    }
    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
        int t = 0;
        vector<int> ans;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                t += a[i];
            }
            if (i < b.size()) {
                t += b[i];
            }
            ans.push_back(t % 10);
            t /= 10;
        }
        if (t) {
            ans.push_back(1);
        }
        if (ans.size() != c.size()) {
            return false;
        }
        for (int i = 0; i < c.size(); ++i) {
            if (ans[i] != c[i]) {
                return false;
            }
        }
        return true;
    }
};