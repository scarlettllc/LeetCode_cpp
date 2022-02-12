class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (auto & c : text) {
            ++m[c];
        }
        return min(min(min(m['b'], m['a']), min(m['l'] / 2, m['o'] / 2)), m['n']);
    }
};