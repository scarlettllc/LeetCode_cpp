class MyCalendar {
private:
    vector<pair<int, int>> cals;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for (auto & [l, r] : cals) {
            if (l < end && start < r) {
                return false;
            }
        }
        cals.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */