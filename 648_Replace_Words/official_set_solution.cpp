class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> dic(dictionary.begin(), dictionary.end());
        vector<string> words;
        int i = 0, n = sentence.size();
        while (i < n) {
            string temp = "";
            while (i < n && sentence[i] != ' ') {
                temp += sentence[i++];
            }
            words.push_back(temp);
            ++i;
        }
        for (auto & word : words) {
            for (int i = 0; i < word.size(); ++i) {
                string temp = word.substr(0, i);
                if (dic.count(temp)) {
                    word = temp;
                }
            }
        }
        string result = words[0];
        for (int i = 1; i < words.size(); ++i) {
            result += " " + words[i];
        }
        return result;
    }
};