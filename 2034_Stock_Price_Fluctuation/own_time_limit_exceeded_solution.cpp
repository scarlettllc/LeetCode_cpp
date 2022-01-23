
bool cmp(const pair<int,int>& p1,const pair<int,int>& p2) 
{
	return p1.second < p2.second;
}
class StockPrice {
private:
    map<int, int> m;
    vector<pair<int, int>> m_by_value;
    map<int, int>::iterator it;
    int maximum_value = 0, minimum_value = 1e9 + 1;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if (m.count(timestamp)) {
            for (int i = 0; i < m_by_value.size(); ++i) {
                if (m_by_value[i].first == timestamp) {
                    m_by_value[i].second = price;
                }
            }
        } else {
            m_by_value.push_back(make_pair(timestamp, price));
        }
        m[timestamp] = price;
        sort(m_by_value.begin(), m_by_value.end(), cmp);
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return m_by_value.back().second;
    }
    
    int minimum() {
        return m_by_value.begin()->second;
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