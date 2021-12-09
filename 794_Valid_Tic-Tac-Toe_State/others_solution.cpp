class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        unordered_map<char, int> m = {{'X', 0}, {'O', 0}, {' ', 0}};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ++m[board[i][j]];
            }
        }
        if (m['O'] > m['X']) {
            return false;
        }
        if (m['X'] > m['O'] + 1) {
            return false;
        }
        set<char> winners;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winners.insert(board[i][0]);
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                winners.insert(board[0][j]);
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winners.insert(board[0][0]);
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            winners.insert(board[2][0]);
        }
        winners.erase(' ');
        if (winners.size() == 1) {
            if (winners.count('X')) {
                if (m['X'] != m['O'] + 1) {
                    return false;
                }
            } else {
                if (m['O'] != m['X']) {
                    return false;
                }
            }
        } else if (winners.size() == 2) {
            return false;
        }
        return true;
    }
};