vector<int> _nums1;
vector<int> _nums2;
struct compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return _nums1[a[0]] + _nums2[a[1]] > _nums1[b[0]] + _nums2[b[1]];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        _nums1 = nums1;
        _nums2 = nums2;
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < min(m, k); ++i) {
            pq.push({i, 0});
        }
        while (k && !pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            result.push_back({nums1[top[0]], nums2[top[1]]});
            --k;
            if (top[1] + 1 < n) {
                pq.push({top[0], top[1] + 1});
            }
        }
        return result;
    }
};