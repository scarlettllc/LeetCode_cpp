class Solution {
private:
    vector<string> candidates;
    int m, n;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                candidates.push_back(to_string(i) + "_" + to_string(j));
            }
        }
        random_shuffle(candidates.begin(), candidates.end());
    }
    
    vector<int> flip() {
        string candidate = candidates.back();
        candidates.pop_back();
        int pos = candidate.find('_');
        return {stoi(candidate.substr(0, pos)), stoi(candidate.substr(pos + 1))};
    }
    
    void reset() {
        candidates.clear();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                candidates.push_back(to_string(i) + "_" + to_string(j));
            }
        }
        random_shuffle(candidates.begin(), candidates.end());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */