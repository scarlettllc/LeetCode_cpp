class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        double s = sqrt(area);
        int L = int(s);
        if (L == s) {
            return {L, L};
        } else {
            for (int i = L + 1; i <= area; ++i) {
                if (area % i == 0) {
                    return {i, area / i};
                }
            }
        }
        return {};
    }
};