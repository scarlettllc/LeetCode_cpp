class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size(), result = n, index1 = -1, index2 = -1;
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1) {
                index1 = i;
            } else if (words[i] == word2) {
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                result = min(result, abs(index1 - index2));
            }
        }
        return result;
    }
};