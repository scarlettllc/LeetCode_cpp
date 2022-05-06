class RecentCounter {
private:
    int count;
    map<int, int> time_count;
public:
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        time_count[t] = ++count;
        int last_time = time_count.lower_bound(t - 3000)->first;
        return time_count[t] - time_count[last_time] + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */