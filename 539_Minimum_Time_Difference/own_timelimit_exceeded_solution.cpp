class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int result = 24 * 60, n = timePoints.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result = min(result, findDifference(timePoints[i], timePoints[j]));
            }
        }
        return result; 
    }
    int findDifference(string a, string b) {
        int a_1 = stoi(a.substr(0, 2));
        int a_2 = stoi(a.substr(3, 2));
        int b_1 = stoi(b.substr(0, 2));
        int b_2 = stoi(b.substr(3, 2));
        if (a_1 > b_1 || (a_1 == b_1 && a_2 > b_2)) {
            return min(Difference(b_1, b_2, a_1, a_2), Difference(a_1, a_2, b_1 + 24, b_2)); 
        } else {
            return min(Difference(a_1, a_2, b_1, b_2), Difference(b_1, b_2, a_1 + 24, a_2));
        }
    }
    int Difference(int a_1, int a_2, int b_1, int b_2) {
        if (a_1 == b_1 && a_2 == b_2) {
            return 0;
        }
        return (b_1 - a_1) * 60 + b_2 - a_2;
    }
};