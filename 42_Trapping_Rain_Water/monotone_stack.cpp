class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size(), top, left, current_length, current_height, result = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                left = stk.top();
                current_length = i - left - 1;
                current_height = min(height[left], height[i]) - height[top];
                result += (current_length * current_height);
            }
            stk.push(i);
        }
        return result;
    }
};