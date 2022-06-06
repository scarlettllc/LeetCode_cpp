class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for (auto & pile : piles) {
            high = max(high, pile);
        }
        while (low < high) {
            int speed = low + (high - low) / 2;
            int time = getTime(piles, speed);
            if (time <= h) {
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return low;
    }
    int getTime(vector<int>& piles, int speed) {
        int result = 0;
        for (auto & pile : piles) {
            result += (pile + speed - 1) / speed;
        }
        return result;
    }
};