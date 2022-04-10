class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        vector<string> morses{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (auto & word : words) {
            string temp = "";
            for (int i = 0; i < word.size(); ++i) {
                temp += morses[word[i] - 'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};