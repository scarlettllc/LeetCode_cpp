class NumArray {
public:
    vector<int> presum;
    vector<int> _nums;
    int n;
    NumArray(vector<int>& nums) {
        _nums = nums;
        int sum = 0;
        n = nums.size();
        presum.push_back(0);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            presum.push_back(sum);
        }
    }
    
    void update(int index, int val) {
        for (int i = index + 1; i <= n; ++i) {
            presum[i] += (val - _nums[index]);
        }
        _nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return presum[right + 1] - presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */