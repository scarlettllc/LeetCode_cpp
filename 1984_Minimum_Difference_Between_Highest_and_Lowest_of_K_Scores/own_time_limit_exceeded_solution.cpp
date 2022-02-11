class Solution {
private:
    vector<int> temp;
    set<int> result;
public:
    void dfs(int cur, int n, vector<int>& nums, int k) {
        if (temp.size() + n - cur + 1 < k) {
            return;
        }
        if (temp.size() == k) {
            result.insert(abs(*max_element(temp.begin(), temp.end()) -
            *min_element(temp.begin(), temp.end())));
            return;
        }
        temp.push_back(nums[cur]);
        dfs(cur + 1, n, nums, k);
        temp.pop_back();
        dfs(cur + 1, n, nums, k);
    }

    int minimumDifference(vector<int>& nums, int k) {
        dfs(0, nums.size() - 1, nums, k);
        return *result.begin();
    }
};