class Solution {
private:
    map<vector<int>, int> memo;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        vector<vector<int>> filter_special;
        for (auto & sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += price[i] * sp[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filter_special.push_back(sp);
            }
        }
        return dfs(price, filter_special, needs, n);
    }
    int dfs(vector<int>& price, vector<vector<int>>& filter_special, vector<int> curNeeds, int& n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i];
            }
            for (auto & sp : filter_special) {
                vector<int> nxNeeds;
                for (int i = 0; i < n; ++i) {
                    if (sp[i] > curNeeds[i]) {
                        break;
                    }
                    nxNeeds.push_back(curNeeds[i] - sp[i]);
                }
                if (nxNeeds.size() == n) {
                    minPrice = min(minPrice, dfs(price, filter_special, nxNeeds, n) + sp[n]);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};