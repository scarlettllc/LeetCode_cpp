class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += machines[i];
        }
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        int result = 0;
        int num = 0;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            num = machines[i] - avg;
            sum += num;
            result = max(result, max(abs(sum), num));
        }
        return result;
    }
};