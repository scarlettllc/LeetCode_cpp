class AllOne {
public:
    map<string, int> string_count;
    map<int, set<string>> count_strings;
    AllOne() {

    }
    
    void inc(string key) {
        int temp = string_count.count(key) ? string_count[key] : 0;
        ++string_count[key];
        if (count_strings.count(temp) && count_strings[temp].count(key)) {
            count_strings[temp].erase(key);
            if (count_strings[temp].size() == 0) {
                count_strings.erase(temp);
            }
        }
        count_strings[temp + 1].insert(key);
    }
    
    void dec(string key) {
        int temp = string_count[key];
        --string_count[key];
        if (string_count[key] == 0) {
            string_count.erase(key);
        }
        count_strings[temp].erase(key);
        if (count_strings[temp].size() == 0) {
            count_strings.erase(temp);
        }
        if (temp > 1) {
            count_strings[temp - 1].insert(key);
        }
    }
    
    string getMaxKey() {
        if (count_strings.size() > 0) {
            return *count_strings.rbegin()->second.begin();
        } else {
            return "";
        }
    }
    
    string getMinKey() {
        if (count_strings.size() > 0) {
            return *count_strings.begin()->second.begin();
        } else {
            return "";
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */