class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> sorted_words(words.begin(), words.end());
        map<int, int> order_map;
        for (int i = 0; i < order.size(); ++i) {
            order_map[order[i]] = i;
        }
        sort(sorted_words.begin(), sorted_words.end(), [&](const string & s1, const string & s2){
            int m = s1.size(), n = s2.size(), len = min(m, n);
            for (int i = 0; i < len; ++i) {
                if (order_map[s1[i]] > order_map[s2[i]]) {
                    return false;
                } else if (order_map[s1[i]] < order_map[s2[i]]) {
                    return true;
                }
            }
            if (m < n) {
                return true;
            } else {
                return false;
            }
        });
        return sorted_words == words;
    }
};