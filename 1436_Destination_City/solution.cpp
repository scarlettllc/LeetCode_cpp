class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> start;
        set<string> end;
        for (int i = 0; i < paths.size(); ++i) {
            if (start.find(paths[i][0]) == start.end()) {
                start.insert(paths[i][0]);
            }
            if (end.find(paths[i][1]) == end.end()) {
                end.insert(paths[i][1]);
            }
        }
        for (set<string>::iterator it = end.begin(); it != end.end(); ++it) {
            if (start.find(*it) == start.end()) {
                return *it;
            }
        }
        return "";
    }
};