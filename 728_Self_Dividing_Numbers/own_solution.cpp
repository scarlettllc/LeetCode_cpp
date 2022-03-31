class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            if (selfDividing(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
    bool selfDividing(int num) {
        int ori_num = num;
        vector<int> candidates;
        while (num) {
            int candidate = num % 10;
            if (candidate == 0) {
                return false;
            }
            num /= 10;
            candidates.push_back(candidate);
        }
        for (auto & candidate : candidates) {
            if (ori_num % candidate) {
                return false;
            }
        }
        return true;
    }
};