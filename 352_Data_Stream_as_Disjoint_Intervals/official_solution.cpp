class SummaryRanges {
private:
    map<int, int> intervals;
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        map<int, int>::iterator interval1 = intervals.upper_bound(val);
        map<int, int>::iterator interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));
        if (interval0 != intervals.end() && val >= interval0->first && val <= interval0->second) {
            return;
        }
        int left_side = (interval0 != intervals.end() && val == interval0->second + 1);
        int right_side = (interval1 != intervals.end() && val == interval1->first - 1);
        if (left_side && right_side) {
            int left = interval0->first;
            int right = interval1->second;
            intervals.erase(interval0);
            intervals.erase(interval1);
            intervals.emplace(left, right);
        } else if (left_side) {
            int left = interval0->first;
            intervals.erase(interval0);
            intervals.emplace(left, val);
        } else if (right_side) {
            int right = interval1->second;
            intervals.erase(interval1);
            intervals.emplace(val, right);
        } else {
            intervals.emplace(val, val);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        map<int, int>::iterator iter;
        for (iter = intervals.begin(); iter != intervals.end(); ++iter) {
            result.push_back({iter->first, iter->second});
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