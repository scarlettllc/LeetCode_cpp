class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }
        int n = nums.size();
        nums.push_back(val);
        indices[val] = n;
        return true;
    }
    
    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }
        int n = nums.size();
        if (indices[val] == n - 1) {
            nums.pop_back();
            indices.erase(val);
        } else {
            int last = nums.back();
            int index = indices[val];
            nums[index] = last;
            indices[last] = index;
            nums.pop_back();
            indices.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */