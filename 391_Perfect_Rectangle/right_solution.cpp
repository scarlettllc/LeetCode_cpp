class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = 100001, right = -100001, down = 100001, up = -100001;
        unordered_map<string, int> point_map;
        int sum = 0;
        for (auto & rectangle : rectangles) {
            int x = rectangle[0], y = rectangle[1], a = rectangle[2], b = rectangle[3];
            sum += (a - x) * (b - y);
            left = min(left, x);
            right = max(right, a);
            down = min(down, y);
            up = max(up, b);
        }
        for (auto & rectangle : rectangles) {
            int x = rectangle[0], y = rectangle[1], a = rectangle[2], b = rectangle[3];
            ++point_map[to_string(x) + "," + to_string(y)];
            ++point_map[to_string(x) + "," + to_string(b)];
            ++point_map[to_string(a) + "," + to_string(y)];
            ++point_map[to_string(a) + "," + to_string(b)];
        }
        string left_down = to_string(left) + "," + to_string(down);
        string left_up = to_string(left) + "," + to_string(up);
        string right_down = to_string(right) + "," + to_string(down);
        string(right_up) = to_string(right) + "," + to_string(up);
        if ((right - left) * (up - down) != sum) {
            return false;
        }
        if (point_map[left_down] != 1 || point_map[left_up] != 1 || point_map[right_down] != 1 || point_map[right_up] != 1) {
            return false;
        }
        unordered_map<string, int>::iterator it;
        for (it = point_map.begin(); it != point_map.end(); ++it) {
            string point = it->first;
            if (point != left_down && point != left_up && point != right_down && point != right_up) {
                int count = it->second;
                if (count != 2 && count != 4) {
                    return false;
                }
            }
        }
        return true;
    }
};