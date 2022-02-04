class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int result = 0, k = 0;
        for (auto & rectangle : rectangles) {
            if (min(rectangle[0], rectangle[1]) > k) {
                k = min(rectangle[0], rectangle[1]);
                result = 1;
            } else if(min(rectangle[0], rectangle[1]) == k){
                ++result;
            }
        }
        return result;
    }
};