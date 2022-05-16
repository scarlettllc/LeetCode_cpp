class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<int, int> order_map;
        for (int i = 0; i < order.size(); ++i) {
            order_map[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i], word2 = words[i + 1];
            int m = word1.size(), n = word2.size(), len = min(m, n);
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (order_map[word1[j]] != order_map[word2[j]]) {
                    if (order_map[word1[j]] > order_map[word2[j]]) {
                        return false;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && m > n) {
                return false;
            }
        }
        return true;
    }
};