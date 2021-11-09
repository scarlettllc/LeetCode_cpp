#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
    int ans, used;
    unordered_map<char, int> rem;
    stack<pair<char, int>> st;

    void dfs(int pos, string &board) {
        if (used >= ans)
            return;

        if (pos == board.size()) {
            if (st.empty())
                ans = used;
            return;
        }
        
        if (!st.empty() && st.top().first == board[pos]) {
            st.top().second++;
        } else {
            st.emplace(board[pos], 1);
        }

        if (st.top().second >= 3) {
            if (pos + 1 == board.size() || board[pos + 1] != board[pos]) {
            // 后面没有相同颜色的球，可以直接消去
                auto tmp = st.top();    
                st.pop();
                dfs(pos + 1, board);
                st.push(tmp);
            } else {
            // 后面有相同颜色的球，必须插入与当前位置不同色的小球进行分隔
                for (auto ch_num : rem) {
                	char ch = ch_num.first;
                	int num = ch_num.second;
                    if (ch == board[pos])
                        continue;
                    for (int j = 1; j <= min(3, num); ++j) {
                        rem[ch] -= j;
                        used += j;
                        auto tmp = st.top();    
                        st.pop();
                        if (!st.empty() && st.top().first == ch) {
                            st.top().second += j;
                        } else {
                            st.emplace(ch, j);
                        }
                        if (st.top().second >= 3) {
                            auto tmp2 = st.top();
                            st.pop();
                            dfs(pos + 1, board);
                            st.push(tmp2);
                        } else {
                            dfs(pos + 1, board);
                        }
                        if (st.top().second > j) {
                            st.top().second -= j;
                        } else {
                            st.pop();
                        }
                        st.push(tmp);
                        used -= j;
                        rem[ch] += j;
                    }
                }
            }
        }
        
        // 插入与当前位置同色的小球
        if (rem[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
            int lim = rem[board[pos]];
            for (int i = 1; i <= min(2, lim); ++i) {
                rem[board[pos]] -= i;
                used += i;
                st.top().second += i;
                if (st.top().second >= 3) {
                    auto tmp = st.top();
                    st.pop();
                    dfs(pos + 1, board);
                    st.push(tmp);
                } else {
                    dfs(pos + 1, board);
                }
                st.top().second -= i;
                used -= i;
                rem[board[pos]] += i;
            }
        }
        
        if (st.top().second < 3 || (st.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
            dfs(pos + 1, board);

        if (st.top().second == 1) {
            st.pop();
        } else {
            st.top().second--;
        }
    }
public:
    int findMinStep(string board, string hand) {
        for (char ch : hand)
            rem[ch]++;

        ans = 1e9;
        used = 0;
        dfs(0, board);
        return ans == 1e9 ? -1 : ans;
    }
};

int main() {
	Solution solution;
	string board = "RBYYBBRRB", hand = "YRBGB";
	int result = solution.findMinStep(board, hand);
	cout << "result = " << result << endl;
}
