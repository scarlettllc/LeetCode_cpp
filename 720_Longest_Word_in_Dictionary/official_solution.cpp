class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string & s1, const string & s2)
        {   
            if (s1.size() != s2.size()) {
                return s1.size() <= s2.size();   
            } else {
                return s1 > s2;
            }
            
        }   );
        string result = "";
        unordered_set<string> s;
        s.emplace("");
        for (auto & word : words) {
            if (s.count(word.substr(0, word.size() - 1))) {
                s.emplace(word);
                result = word;
            }
        }
        return result;
    }
};