class WordDictionary {
private:
    set<string> dic;
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        if (dic.find(word) == dic.end()) {
            dic.insert(word);
        }
    }
    
    bool search(string word) {
        if (dic.find(word) != dic.end()) {
            return true;
        }
        set<string>::iterator it;
        for (it = dic.begin(); it != dic.end(); ++it) {
            string temp = *it;
            if (temp.size() != word.size()) {
                continue;
            }
            bool flag = true;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == temp[i] || word[i] == '.') {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */