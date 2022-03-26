class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (auto & op : ops) {
            switch(op[0]){
                case '+':
                    score.push_back(score[score.size() - 1] + score[score.size() - 2]);
                    break;
                case 'D':
                    score.push_back(score[score.size() - 1] * 2);
                    break;
                case 'C':
                    score.pop_back();
                    break;
                default:
                    score.push_back(stoi(op));
            }  
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};