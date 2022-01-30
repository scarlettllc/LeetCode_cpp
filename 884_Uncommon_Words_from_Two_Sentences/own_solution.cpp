class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s1_list = string2wordlist(s1);
        vector<string> s2_list = string2wordlist(s2);
        map<string, int> m;
        for (auto & word : s1_list) {
            ++m[word];
        }
        for (auto & word : s2_list) {
            ++m[word];
        }
        vector<string> result;
        for (auto & it : m) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
    vector<string> string2wordlist(string s) {
        int n = s.size(), i = 0, j;
        vector<string> result;
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            j = i;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            result.push_back(s.substr(i, j - i));
            i = j;
        }
        return result;
    }
};