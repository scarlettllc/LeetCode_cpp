class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int x = rand() % total;
        --total;
        vector<int> result;
        if (map.count(x)) {
            result = {map[x] / n, map[x] % n};
        } else {
            result = {x / n, x % n};
        }
        if (map.count(total)) {
            map[x] = map[total];
        } else {
            map[x] = total;
        }
        return result;
    }
    
    void reset() {
        total = m * n;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */