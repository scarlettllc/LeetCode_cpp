class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start == destination) {
            return 0;
        }
        distance.insert(distance.end(), distance.begin(), distance.end());
        if (start > destination) {
            int temp = start;
            start = destination;
            destination = temp;
        }
        int first = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        int second = accumulate(distance.begin() + destination, distance.begin() + start + distance.size() / 2, 0);
        return min(first, second);
    }
};