class StockPrice {
private:
    map<int, int> m;
    multiset<int> s;
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        int prev_price = m.count(timestamp)? m[timestamp] : 0;
        m[timestamp] = price;
        if (prev_price > 0) {
            auto it = s.find(prev_price);
            if (it != s.end()) {
                s.erase(it);
            }
        }
        s.emplace(price);
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */