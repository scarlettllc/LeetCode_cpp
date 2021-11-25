class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int iterations = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(iterations));
    }
};

/*
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
*/