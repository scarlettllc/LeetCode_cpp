class DetectSquares {
private:
    map<vector<int>, int> m;
    map<int, vector<vector<int>>> a2candidates;
    map<int, vector<vector<int>>> b2candidates;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        ++m[point];
        a2candidates[point[0]].push_back(point);
        b2candidates[point[1]].push_back(point);
    }
    
    int count(vector<int> point) {
        int result = 0;
        int a = point[0], b = point[1];
        vector<vector<int>> a_candidates = a2candidates[a];
        vector<vector<int>> b_candidates = b2candidates[b];
        for (auto & a_candidate : a_candidates) {
            for (auto & b_candidate : b_candidates) {
                if (a_candidate[0] == a && a_candidate[1] == b) {
                    continue;
                }
                if (b_candidate[0] == a && b_candidate[1] == b) {
                    continue;
                }
                if (abs(a_candidate[1] - b) == abs(b_candidate[0] - a)) {
                    result += m[{b_candidate[0], a_candidate[1]}];
                }
            }
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */