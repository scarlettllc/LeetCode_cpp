class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string str = "12210111011122000010020202";
        vector<string> result;
        for (auto & word : words) {
            bool flag = true;
            set<char> s;
            for (auto & ch : word) {
                char temp = str[tolower(ch) - 'a'];
                if (!s.count(temp)) {
                    s.insert(temp);
                }
                if (s.size() > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(word);
            }
        }
        return result;
    }
};