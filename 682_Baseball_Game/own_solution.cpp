class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (auto & op : ops) {
            if (op == "+") {
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            } else if (op == "D") {
                score.push_back(score[score.size() - 1] * 2);
            } else if (op == "C") {
                score.pop_back();
            } else {
                score.push_back(stoi(op));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};