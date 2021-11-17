class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> word_map;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            int m = word.size();
            int temp = 0;
            for (int j = 0; j < m; ++j) {
                temp |= (1 << (word[j] - 'a'));
            }
            if (word_map.count(temp)) {
                if (word.size() > word_map[temp]) {
                    word_map[temp] = word.size();
                }
            } else {
                word_map[temp] = word.size();
            }
        }
        int result = 0;
        for (auto [temp1, _] : word_map) {
            for (auto [temp2, _] : word_map) {
                if ((temp1 & temp2) == 0) {
                    result = max(result, word_map[temp1] * word_map[temp2]);
                }
            }
        }
        return result;
    }
};