struct value_frac{
    double value;
    vector<int> frac;
};
void siftDown(vector<value_frac>& candidates, int start, int m) {
    if (candidates.size() == 0) {
        return;
    }
    int i = start, j = 2 * i + 1;
    value_frac temp = candidates[i];
    while (j <= m) {
        if (j < m && candidates[j].value > candidates[j + 1].value) {
            ++j;
        }
        if (temp.value <= candidates[j].value) {
            break;
        } else {
            candidates[i] = candidates[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    candidates[i] = temp;
}
bool removeMin(vector<value_frac>& candidates, value_frac& heap_top) {
    if (candidates.size() == 0) {
        return false;
    }
    heap_top = candidates[0];
    candidates[0] = candidates[candidates.size() - 1];
    candidates.pop_back();
    siftDown(candidates, 0, candidates.size() - 1);
    return true;
}
void create_min_heap(vector<value_frac>& candidates) {
    int currentSize = candidates.size();
    int currentPos = (currentSize - 2) / 2;
    while (currentPos >= 0) {
        siftDown(candidates, currentPos, currentSize - 1);
        --currentPos;
    }
}
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<value_frac> candidates;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                value_frac candidate = {(double)arr[i] / arr[j], {arr[i], arr[j]}};
                candidates.push_back(candidate);
            }
        }
        create_min_heap(candidates);
        value_frac heap_top;
        int i = 0;
        while (i < k) {
            removeMin(candidates, heap_top);
            ++i;
        }
        return heap_top.frac;
    }
};