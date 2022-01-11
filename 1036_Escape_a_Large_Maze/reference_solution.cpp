class Solution {
public:
    int EDGE = 1e6, MAX = 1e5;
    long long BASE = 13331;
    unordered_set<long long> set;
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
        for(auto& p : blocked) set.insert(p[0] * BASE + p[1]);
        int n = blocked.size();
        MAX = n * (n - 1) / 2; // 可直接使用 1e5
        return check(s, t) and check(t, s);
    }
    bool check(vector<int>& a, vector<int>& b){
        unordered_set<long long> vis;
        queue< pair<int,int> > q;
        q.push( {a[0], a[1]});
        vis.insert(a[0] * BASE + a[1]);
        while(q.size() and vis.size() <= MAX){
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if(x == b[0] and y == b[1]) return true;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 or nx >= EDGE or ny < 0 or ny >= EDGE) continue;
                if(set.count(nx * BASE + ny)) continue;
                if(vis.count(nx * BASE + ny)) continue;
                q.push( {nx, ny} );
                vis.insert(nx * BASE + ny);
            }
        }
        return vis.size() > MAX;
    }
};

作者：AC_OIer
链接：https://leetcode-cn.com/problems/escape-a-large-maze/solution/gong-shui-san-xie-bfs-gei-ding-zhang-ai-8w63o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。