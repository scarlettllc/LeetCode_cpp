class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int m = list1.size(), n = list2.size(), i = 0, j = 0;
        map<int, vector<string>> result_map;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (list1[i] == list2[j]) {
                    result_map[i + j].push_back(list1[i]);
                }
            }
        }
        return result_map.begin()->second;
    }
};