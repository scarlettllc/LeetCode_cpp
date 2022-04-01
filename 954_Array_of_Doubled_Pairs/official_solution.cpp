class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto & num : arr) {
            ++cnt[num];
        }
        if (cnt[0] % 2) {
            return false;
        }
        vector<int> vals;
        for (auto & [num, _] : cnt) {
            vals.push_back(num);
        }
        sort(vals.begin(), vals.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) {
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};