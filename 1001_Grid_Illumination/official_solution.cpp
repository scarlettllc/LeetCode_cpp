class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int, int>> points;
        unordered_map<int, int> rows, cols, diagonals, antidiagonals;
        for (auto & lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (points.count({i, j})) {
                continue;
            }
            points.insert({i, j});
            ++rows[i];
            ++cols[j];
            ++diagonals[i - j];
            ++antidiagonals[i + j];
        }
        vector<int> result;
        for (auto & query : queries) {
            int i = query[0], j = query[1];
            if (rows[i] || cols[j] || diagonals[i - j] || antidiagonals[i + j]) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        continue;
                    } 
                    if (points.count({x, y})) {
                        points.erase({x, y});
                        --rows[x];
                        --cols[y];
                        --diagonals[x - y];
                        --antidiagonals[x + y];
                    }
                }
            }
        }
        return result;
    }
};