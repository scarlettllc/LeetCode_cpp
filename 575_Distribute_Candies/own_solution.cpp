class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for (auto & candy : candyType) {
            if (!s.count(candy)) {
                s.insert(candy);
            }
        }
        if (s.size() >= candyType.size() / 2) {
            return candyType.size() / 2;
        } else {
            return s.size();
        }
    }
};