class Solution {
private:
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int self = 0;
        double m_pi_2 = 2 * M_PI;
        vector<double> candidates;
        for (auto& point : points) {
            if (point == location) {
                ++self;
                continue;
            }
            double temp_angle = atan2(point[1] - location[1], point[0] - location[0]);
            if (temp_angle < 0) {
                temp_angle += m_pi_2;
            }
            candidates.push_back(temp_angle);
        }
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        for (int i = 0; i < n; ++i) {
            candidates.push_back(m_pi_2 + candidates[i]);
        }
        int result = 0;
        double degree = angle * M_PI / 180;
        for (int i = 0; i < n; ++i) {
            double start = candidates[i];
            int end_pos = upper_bound(candidates.begin(), candidates.end(), start + degree) - candidates.begin();
            result = max(result, end_pos - i);
        }
        if (self) {
            result += self;
        }
        return result;
    }
};