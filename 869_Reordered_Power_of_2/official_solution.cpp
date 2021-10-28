class Solution {
private:
    unordered_set<string> powerOf2Digits;
public: 
    Solution() {
        for (int i = 1; i <= 1e9; i <<= 1) {
            powerOf2Digits.insert(countDigits(i));
        }
    }
    string countDigits(int n) {
        string result(10, 0);
        while (n) {
            ++result[n % 10];
            n /= 10;
        }
        return result;
    }
    bool reorderedPowerOf2(int n) {
        return powerOf2Digits.count(countDigits(n));
    }
};