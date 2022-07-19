class MyCalendarTwo {
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for (auto & [l, r] : overlaps) {
            if (start < r && l < end) {
                return false;
            }
        }
        for (auto & [l, r] : booked) {
            if (start < r && l < end) {
                overlaps.emplace_back(max(start, l), min(end, r));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */