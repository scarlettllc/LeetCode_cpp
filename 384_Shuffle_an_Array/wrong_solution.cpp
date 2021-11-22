class Solution {
private:
    vector<int> private_nums;
    int * shuffled_array;
public:
    Solution(vector<int>& nums) {
        private_nums.insert(private_nums.begin(), nums.begin(), nums.end());
        shuffled_array = new int[private_nums.size()];
        for (int i = 0; i < private_nums.size(); ++i) {
            shuffled_array[i] = i;
        }
    }
    
    vector<int> reset() {
        return private_nums;
    }
    
    vector<int> shuffle() {
        srand(time(0)*1000000000);
        random_shuffle(shuffled_array, shuffled_array + private_nums.size());
        vector<int> result(private_nums.size());
        for (int i = 0; i < result.size(); ++i) {
            result[i] = private_nums[shuffled_array[i]];
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
