class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> rank_list;
        for (int i = 0; i < n; ++i) {
            rank_list.push_back(make_pair(-score[i], i));
        }
        sort(rank_list.begin(), rank_list.end());
        vector<string> desc{"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i >= 3) {
                result[rank_list[i].second] = to_string(i + 1); 
            } else {
                result[rank_list[i].second] = desc[i];
            }
        }
        return result;
    }
};