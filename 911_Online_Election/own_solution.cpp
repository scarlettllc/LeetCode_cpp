class TopVotedCandidate {
private:
    vector<int> _persons;
    vector<int> _times;
    unordered_map<int, int> time_map;
    unordered_map<int, int> count_map;
    unordered_map<int, int>::iterator it;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->_persons = persons;
        this->_times = times;
        int temp_candidate, temp_max_count;
        for (int i = 0; i < times.size(); ++i) {
            ++count_map[persons[i]];
            temp_candidate = -1;
            temp_max_count = 0;
            it = max_element(count_map.begin(), count_map.end(), 
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second; 
                });
            temp_max_count = it->second;
            vector<int> temp_candidates;
            for (it = count_map.begin(); it != count_map.end(); ++it) {
                if (it->second == temp_max_count) {
                    temp_candidates.push_back(it->first);
                }
            }
            for (int j = i; j >= 0; --j) {
                if (find(temp_candidates.begin(), temp_candidates.end(), persons[j]) != temp_candidates.end()) {
                    temp_candidate = persons[j];
                    break;
                }
            }
            time_map[this->_times[i]] = temp_candidate;
        }
    }
    
    int q(int t) {
        vector<int>::iterator it = lower_bound(this->_times.begin(), this->_times.end(), t);
        int pos = distance(_times.begin(), it);
        if (pos == _times.size()) {
            --pos;
        }
        if (_times[pos] > t) {
            --pos;
        }
        return time_map[_times[pos]];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */