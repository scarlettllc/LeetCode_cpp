class Solution {
public:
    int lastRemaining(int n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }
        bool flag = true;
        while (arr.size() > 1) {
            vector<int> temp;
            if (flag) {
                for (int i = 1; i < arr.size(); i += 2) {
                    temp.push_back(arr[i]);
                }
            } else {
                for (int i = arr.size() - 2; i >= 0; i -= 2) {
                    temp.insert(temp.begin(), arr[i]);
                }
            }
            arr = temp;
            flag = !flag;
        }
        return arr[0];
    }
};