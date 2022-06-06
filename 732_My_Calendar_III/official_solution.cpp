class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        int result = 0, max_k = 0;
        ++cnt[start];
        --cnt[end];
        for (auto & [_, freq] : cnt) {
            max_k += freq;
            result = max(result, max_k);
        }
        return result;
    }
private:
    map<int, int> cnt;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */