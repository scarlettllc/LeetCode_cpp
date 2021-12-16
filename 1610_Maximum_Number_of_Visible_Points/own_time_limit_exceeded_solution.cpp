class Solution {
private:
    const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286209;
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int self = 0;
        vector<double> candidates;
        for (auto& point : points) {
            if (point == location) {
                ++self;
                continue;
            }
            double tan_angle = double(point[1] - location[1]) / (point[0] - location[0]);
            cout << tan_angle << endl;
            double temp_angle = atan2(point[1] - location[1], point[0] - location[0]) * 180 / pi;
            if (temp_angle < 0) {
                temp_angle += 360;
            }
            cout << temp_angle << endl;
            candidates.push_back(temp_angle);
        }
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            cout << candidates[i] << " ";
        }
        cout << endl;
        int n = candidates.size();
        for (int i = 0; i < n; ++i) {
            candidates.push_back(360 + candidates[i]);
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            double start = candidates[i];
            int end_pos = upper_bound(candidates.begin(), candidates.end(), start + angle) - candidates.begin();
            result = max(result, end_pos - i);
        }
        if (self) {
            result += self;
        }
        return result;
    }
};