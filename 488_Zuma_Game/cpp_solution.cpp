class Solution {
public:
    map<string, int> result_map;
    string b;
    int findMinStep(string board, string hand) {
        int m = hand.size(), cur = (1 << m);
        b = hand;
        int result = dfs(board, cur);
        return result == 20 ? -1 : result;
    }
    int dfs(string a, int cur) {
        if (a.size() == 0) {
            return 0;
        }
        if (result_map.find(a) != result_map.end()) {
            return result_map[a];
        }
        int result = 20;
        int n = a.size(), m = b.size();
        for (int i = 0; i < m; ++i) {
            if (((cur >> i) & 1) == 1) {
                continue;
            }
            int next = ((1 << i) | cur);
            for (int j = 0; j <= n; ++j) {
                bool flag = false;
                if (j > 0 && j < n && a[j - 1] == a[j] && a[j - 1] != b[i]) {
                    flag = true;
                }
                if (j < n && a[j] == b[i]) {
                    flag = true;
                }
                if (!flag) {
                    continue;
                }
                string temp = a.substr(0, j) + b[i] + a.substr(j);
                int k = j;
                while (k >= 0 && k < temp.size()) {
                    int l = k, r = k;
                    while (l >= 0 && temp[l] == temp[k]) {
                        --l;
                    }
                    while (r < temp.size() && temp[r] == temp[k]) {
                        ++r;
                    }
                    if (r - l - 1 >= 3) {
                        temp = temp.substr(0, l + 1) + temp.substr(r);
                        k = l + 1;
                    } else {
                        break;
                    }
                }
                result = min(result, dfs(temp, next) + 1);
            }
        }
        result_map[a] = result;
        return result;
    }
};