class Solution {
private:
    vector<int> private_nums;
    vector<int> shuffled_nums;
public:
    Solution(vector<int>& nums) {
        private_nums.insert(private_nums.begin(), nums.begin(), nums.end());
        shuffled_nums.insert(shuffled_nums.begin(), nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return private_nums;
    }
    
    vector<int> shuffle() {
        random_shuffle(shuffled_nums.begin(), shuffled_nums.end());
        return shuffled_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */