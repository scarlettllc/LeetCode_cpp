class RandomizedSet {
private:
    vector<int> list;
    set<int> s;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (!s.count(val)) {
            s.insert(val);
            list.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (s.count(val)) {
            s.erase(val);
            list.erase(std::remove(list.begin(), list.end(), val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = list.size();
        return list[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */