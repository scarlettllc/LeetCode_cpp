class SummaryRanges {
private:
    vector<int> nums;
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        if (find(nums.begin(), nums.end(), val) == nums.end()) {
            nums.emplace_back(val);
            sort(nums.begin(), nums.end());
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int start = nums[i];
            ++i;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                ++i;
            }
            result.push_back({start, nums[i - 1]});
            --i;
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */