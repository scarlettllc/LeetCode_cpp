class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), top = 0, i = -1;
        while (top < n) {
            ++i;
            if (arr[i]) {
                ++top;
            } else {
                top += 2;
            }
        }
        int j = n - 1;
        if (top == n + 1) {
            arr[j] = arr[i];
            --j;
            --i;
        }
        while (j > 0) {
            arr[j] = arr[i];
            --j;
            if (!arr[i]) {
                arr[j] = arr[i];
                --j;
            }
            --i;
        }
    }
};