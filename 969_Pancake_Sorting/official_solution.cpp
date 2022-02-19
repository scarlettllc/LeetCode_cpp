class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        for (int n = arr.size(); n > 1; --n) {
            int index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
            if (index == n - 1) {
                continue;
            }
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + n);
            result.push_back(index + 1);
            result.push_back(n);
        }
        return result;
    }
};