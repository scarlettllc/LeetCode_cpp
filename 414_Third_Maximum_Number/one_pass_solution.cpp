class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            } else if (nums[i] < a && nums[i] > b) {
                c = b;
                b = nums[i];
            } else if (nums[i] < b && nums[i] > c) {
                c = nums[i];
            }
        }
        return c == LONG_MIN ? a : c;
    }
};

/*
第一种方法：先排序，然后找第三大的数，时间复杂度O(nlogn)，空间复杂度O(logn)，通用；
第二种方法：用nums初始化集合，直接用指针访问最大的或者是第三大的，空间复杂度O(n)，通用；
第三种方法：遍历数组，维护一个长度不超过3的集合，时间复杂度O(n)，空间复杂度O(1)，通用；
第四种方法：遍历数组，用变量a，b，c模拟第一大、第二大、第三大的数，时间复杂度O(n)，空间复杂度O(1)，不通用。
*/