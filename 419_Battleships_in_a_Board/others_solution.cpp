class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    bool flag = true;
                    if ((i != 0 && board[i - 1][j] == 'X') || (j != 0 && board[i][j - 1] == 'X')) {
                        flag = false;
                    }
                    if (flag) {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};