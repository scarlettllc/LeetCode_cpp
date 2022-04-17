class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> words_dict;
        int n = paragraph.size();
        string temp = "";
        string punctuations = "!?',;. ";
        for (int i = 0; i < n; ++i) {
            if (punctuations.find(paragraph[i]) != punctuations.npos) {
                if (temp != "") {
                    bool flag = true;
                    for (auto & ban : banned) {
                        if (temp == ban) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ++words_dict[temp];
                    }
                    temp = "";
                }
            } else{
                temp += tolower(paragraph[i]);
            }
        }
        if (temp != "") {
            ++words_dict[temp];
        }
        auto x = max_element(words_dict.begin(), words_dict.end(), 
        [](const pair<string, int> & p1, const pair<string, int> & p2) {
            return p1.second < p2.second;
        });
        return x->first;
    }
};