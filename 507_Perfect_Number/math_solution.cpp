class Solution {
public:
    bool checkPerfectNumber(int num) {
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
};

/*
根据欧几里得-欧拉定理，每个偶完全数可以写成2^{p - 1}(2^p - 1)的形式，其中p为素数且2^p - 1为素数。由于目前奇完全数还未被发现，题目范围[1,10^8]内的完全数共有6,28,496,8128,33550336，总共5个。
*/