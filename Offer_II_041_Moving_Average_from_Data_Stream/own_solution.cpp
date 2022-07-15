class MovingAverage {
private:
    int size;
    double sum;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        } 
        q.emplace(val);
        sum += val;
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */