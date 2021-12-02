class Solution {
public:
    void select_sort(vector<int>& score, vector<int>& sorted_idxs) {
        int n = sorted_idxs.size();
        for (int i = 0; i < n - 1; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                if (score[j] > score[k]) {
                    k = j;
                }
            }
            if (k != i) {
                swap(sorted_idxs[i], sorted_idxs[k]);
                swap(score[i], score[k]);
            }
        }
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sorted_idxs;
        for (int i = 0; i < n; ++i) {
            sorted_idxs.push_back(i);
        }
        select_sort(score, sorted_idxs);
        vector<string> result(n);
        result[sorted_idxs[0]] = "Gold Medal";
        if (n >= 2) {
            result[sorted_idxs[1]] = "Silver Medal";
        }
        if (n >= 3) {
            result[sorted_idxs[2]] = "Bronze Medal";
        }
        for (int i = 3; i < n; ++i) {
            result[sorted_idxs[i]] = to_string(i + 1);
        }
        return result;
    }
};