class Solution {
public:
    vector<vector<int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> illuminated(n, vector<int>(n, 0));
        vector<vector<bool>> isOn(n, vector<bool>(n, false));
        for (auto & lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (isOn[i][j]) {
                continue;
            }
            isOn[i][j] = true;
            ++illuminated[i][j];
            for (int y = 0; y < n; ++y) {
                if (y == j) {
                    continue;
                }
                ++illuminated[i][y];
            }
            for (int x = 0; x < n; ++x) {
                if (x == i) {
                    continue;
                }
                ++illuminated[x][j];
            }
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (((x - i == y - j) || x + y == i + j) && (x != i && y != j)) {
                        ++illuminated[x][y];
                    }
                }
            }
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                cout << illuminated[x][y] << "    ";
            }
            cout << endl;
        }
        vector<int> result;
        for (auto & query : queries) {
            int i = query[0], j = query[1];
            cout << i << "   " << j << "   "<< illuminated[i][j] << endl;
            if (illuminated[i][j]) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
            turn_off(i, j, n, illuminated, isOn);
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    cout << illuminated[x][y] << "    ";
                }
                cout << endl;
            }
        }
        return result;
    }
    void turn_off(int i, int j, int n, vector<vector<int>>& illuminated, vector<vector<bool>>& isOn) {
        for (auto & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < n && y >= 0 && y < n && isOn[x][y]) {
                isOn[x][y] = false;
                --illuminated[x][y];
                for (int k = 0; k < n; ++k) {
                    if (k == x) {
                        continue;
                    }
                    --illuminated[k][y];
                }
                for (int l = 0; l < n; ++l) {
                    if (l == y) {
                        continue;
                    }
                    --illuminated[x][l];
                }
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < n; ++l) {
                        if (((k - x == l - y) || (k + l == x + y)) && k != x && l != y) {
                            --illuminated[k][l];
                        }
                    }
                }
            }
        }
    }
};