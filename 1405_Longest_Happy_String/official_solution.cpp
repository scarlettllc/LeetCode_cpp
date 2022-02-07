class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        vector<pair<int, char>> arr{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            sort(arr.begin(), arr.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) {
                return p1.first > p2.first;
            });
            bool hasNext = false;
            for (auto & [freq, ch] : arr) {
                if (freq <= 0) {
                    break;
                }
                int m = result.size();
                if (m >= 2 && result[m - 1] == ch && result[m - 2] == ch) {
                    continue;
                }
                result.push_back(ch);
                --freq;
                hasNext = true;
                break;
            }
            if (!hasNext) {
                break;
            }
        }
        return result;
    }
};