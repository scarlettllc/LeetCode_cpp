class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1, result = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax= max(rightMax, height[right]);
            if (height[left] < height[right]) {
                result += (leftMax - height[left]);
                ++left;
            } else {
                result += (rightMax - height[right]);
                --right;
            }
        }
        return result;
    }
};