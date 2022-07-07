class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stable_sort(dictionary.begin(), dictionary.end(), [&](const string& s1, const string& s2) {
            return (s1.size() < s2.size()? true : false);
        });
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
            for (int i = 0; i < dictionary.size(); ++i) {
                if (word.substr(0, dictionary[i].size()) == dictionary[i]) {
                    word = dictionary[i];
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