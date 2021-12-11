class TopVotedCandidate {
private:
    vector<int> tops;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> counts;
        int top = -1;
        counts[top] = -1;
        for (auto & p : persons) {
            ++counts[p];
            if (counts[p] >= counts[top]) {
                top = p;
            }
            tops.push_back(top);
        }
    }
    
    int q(int t) {
        int pos = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

比你的代码好的地方：
1、用的是upper_bound。
2、直接记录下标对应的top，其实并不需要借助time map。
3、记录了上一个top，这使得比较的使用大于等于可以避免遍历。