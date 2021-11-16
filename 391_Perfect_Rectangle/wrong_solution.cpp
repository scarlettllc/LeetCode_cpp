class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = 100001, right = -100001, down = 100001, up = -100001;
        int sum = 0;
        for (auto & rectangle : rectangles) {
            int x = rectangle[0], y = rectangle[1], a = rectangle[2], b = rectangle[3];
            sum += (a - x) * (b - y);
            left = min(left, x);
            right = max(right, a);
            down = min(down, y);
            up = max(up, b);
        }
        int left_down = 0, left_up = 0, right_down = 0, right_up = 0;
        for (auto & rectangle : rectangles) {
            int x = rectangle[0], y = rectangle[1], a = rectangle[2], b = rectangle[3];
            if (x == left && y == down) {
                ++left_down;
            }
            if (x == left && b == up) {
                ++left_up;
            }
            if (a == right && y == down) {
                ++right_down;
            }
            if (a == right && b == up) {
                ++right_up; 
            }
        }
        if (left_down != 1 || left_up != 1 || right_down != 1 || right_up != 1) {
            return false;
        }
        return (right - left) * (up - down) == sum;
    }
};