class Solution {
public:
    int totalMoney(int n) {
        int batch = n / 7;
        int residue = n % 7;
        return 28 * batch + batch * (batch - 1) * 7 / 2 + residue * (1 + batch) + residue * (residue - 1) / 2;
    }
};