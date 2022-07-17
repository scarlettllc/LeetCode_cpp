class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            while (!visited[i]) {
                visited[i] = true;
                i = nums[i];
                ++count;
            }
            result = max(result, count);
        }
        return result;
    }
};