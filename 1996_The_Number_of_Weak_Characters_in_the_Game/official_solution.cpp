class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), 
            [](const vector<int> &a, const vector<int> &b) {
                return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; 
            });
        int result = 0, n = properties.size(), maxDef = 0;
        for (auto & p : properties) {
            if (p[1] < maxDef) {
                ++result;
            } else {
                maxDef = p[1];
            }
        } 
        return result;
    }
};