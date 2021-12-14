class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto & x, const auto & y){
            return x[1] < y[1];
        });
        priority_queue<int> q;
        int total = 0;
        for (auto & course : courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                q.push(ti);
                total += ti;
            } else {
                if (!q.empty() && q.top() > ti) {
                    total -= (q.top() - ti);
                    q.pop();
                    q.push(ti);
                }
            }
        }
        return q.size();
    }
};