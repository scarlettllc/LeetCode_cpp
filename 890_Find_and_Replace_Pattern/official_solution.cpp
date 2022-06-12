class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (auto & word : words) {
            if (match(word, pattern) && match(pattern, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    bool match(string & word, string & pattern) {
        unordered_map<char, char> m;
        for (int i = 0; i < word.size(); ++i) {
            char c1 = word[i], c2 = pattern[i];
            if (!m.count(c1)) {
                m[c1] = c2;
            } else if (m[c1] != c2) {
                return false;
            }
        }
        return true;
    }
};