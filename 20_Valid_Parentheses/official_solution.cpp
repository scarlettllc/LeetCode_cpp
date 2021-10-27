
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2) {
            return false;
        }
        unordered_map<char, char> pairs{{'}', '{'}, {')', '('}, {']', '['}};
        stack<char> st;
        for (auto& ch : s) {
            if (pairs.count(ch)) {
                if (st.empty() || st.top() != pairs[ch]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};