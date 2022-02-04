class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> m;
        for (auto & rectangle : rectangles) {
            ++m[min(rectangle[0], rectangle[1])];
        }
        return m.rbegin()->second;
    }
};