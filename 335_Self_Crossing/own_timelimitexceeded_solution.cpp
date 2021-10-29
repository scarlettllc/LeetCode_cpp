class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        set<string> s;
        int n = distance.size();
        int x = 0, y = 0;
        s.insert("0,0");
        for (int i = 0; i < n; ++i) {
            int dis = distance[i];
            for (int j = 0; j < dis; ++j) {
                if (i % 4 == 0) {
                    ++y;
                } else if (i % 4 == 1) {
                    --x;
                } else if (i % 4 == 2) {
                    --y;
                } else {
                    ++x;
                }
                string temp = to_string(x) + "," + to_string(y);
                if (!s.count(temp)) {
                    s.insert(temp);
                } else {
                    return true;
                }
            } 
        }
        return false;
    }
};