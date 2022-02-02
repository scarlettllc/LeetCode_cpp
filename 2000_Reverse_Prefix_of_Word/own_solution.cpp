class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if (pos != word.npos) {
            string first = word.substr(0, pos + 1);
            string second = word.substr(pos + 1);
            reverse(first.begin(), first.end());
            return first + second;
        } else {
            return word;
        }
    }
};