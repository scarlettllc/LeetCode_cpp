typedef pair<int, int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int result = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = apples.size();
        int i = 0;
        while (i < n) {
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            int rottenDay = i + days[i];
            int count = apples[i];
            if (count > 0) {
                pq.emplace(rottenDay, count);
            }
            if (!pq.empty()) {
                pii cur = pq.top();
                pq.pop();
                --cur.second;
                ++result;
                if (cur.second > 0) {
                    pq.emplace(cur.first, cur.second);
                }
            }
            ++i;
        }
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            if (pq.empty()) {
                break;
            }
            pii cur = pq.top();
            pq.pop();
            int num = min(cur.first - i, cur.second);
            i += num;
            result += num;
        }
        return result;
    }
};