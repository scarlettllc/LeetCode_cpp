class DetectSquares {
private:
    map<vector<int>, int> m;
    map<int, map<vector<int>, int>> a2candidates;
    map<int, map<vector<int>, int>> b2candidates;
    map<vector<int>, int> temp;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        ++m[point];
        ++a2candidates[point[0]][point];
        ++b2candidates[point[1]][point];
    }
    
    int count(vector<int> point) {
        int result = 0;
        int a = point[0], b = point[1];
        map<vector<int>, int> a_candidates = a2candidates[a];
        map<vector<int>, int> b_candidates = b2candidates[b];
        for (auto & a_candidate : a_candidates) {
            for (auto & b_candidate : b_candidates) {
                if (a_candidate.first[0] == a && a_candidate.first[1] == b) {
                    continue;
                }
                if (b_candidate.first[0] == a && b_candidate.first[1] == b) {
                    continue;
                }
                if (abs(a_candidate.first[1] - b) == abs(b_candidate.first[0] - a)) {
                    result += a_candidate.second * b_candidate.second * m[{b_candidate.first[0], a_candidate.first[1]}];
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