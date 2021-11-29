class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        while (true) {
            double mid = (left + right) / 2;
            int x = 0, y = 1, count = 0, i = -1;
            for (int j = 1; j < n; ++j) {
                while ((double)arr[i + 1] / arr[j] < mid) {
                    ++i;
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];
                    }
                }
                count += (i + 1);
            }
            if (count == k) {
                return {x, y};
            } else if (count > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
    }
};