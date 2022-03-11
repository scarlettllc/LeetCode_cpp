class Solution {
public:
    int n;
    int count;
    vector<vector<int>> children;
    long maxscore;
    int dfs(int node) {
        int size = n - 1;
        long score = 1;
        for (auto & c : children[node]) {
            int t = dfs(c);
            score *= t;
            size -= t;
        }
        if (node != 0) {
            score *= size;
        }
        if (score > maxscore) {
            maxscore = score;
            count = 1;
        } else if (score == maxscore) {
            ++count;
        }
        return n - size;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        count = 0;
        maxscore = 0;
        children.resize(n);
        for (int i = 0; i < n; ++i) {
            if (parents[i] != -1) {
                children[parents[i]].push_back(i);
            }
        }
        dfs(0);
        return count;
    }
};