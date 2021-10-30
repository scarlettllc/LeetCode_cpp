class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto & num : nums) {
            xorsum ^= num;
        }
        int lsb = (xorsum == INT_MIN ? xorsum : (xorsum & (-xorsum)));
        int type1 = 0, type2 = 0;
        for (auto & num : nums) {
            if (num & lsb) {
                type1 ^= num;
            } else {
                type2 ^= num;
            }
        } 
        return {type1, type2};
    }
};

// 假设最终的答案是x1和x2，则将nums中的所有元素做异或操作得到的是x1与x2异或之和，现在需要想办法将x1和x2分离。
// 设x = x1 ^ x2，通过 x & (-x) 的位运算可以得到x的为1的最低位（需要注意处理INT_MIN的临界条件）。
// 设最低位是从右往左数第l位。则必有x1和x2其中一个右起第l位为1，另一个右起第l位为0。
// 现将nums中的所有数按照右起第l位进行分类。分别设为A类和B类。则x1和x2一个在A类，另一个在B类。
// 另一方面，其余的出现两次的元素，要么同时在A类，要么同时在B类。
// 将A类的元素异或求和，则可以得到其中一个只出现一次的元素。将B类的元素异或求和，则可以得到另一个只出现一次元素。
