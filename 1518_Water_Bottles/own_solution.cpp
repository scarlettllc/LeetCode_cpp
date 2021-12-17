class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles, residue = numBottles;
        while (residue / numExchange) {
            result += residue / numExchange;
            residue = (residue / numExchange) + (residue % numExchange);            
        }
        return result;
    }
};