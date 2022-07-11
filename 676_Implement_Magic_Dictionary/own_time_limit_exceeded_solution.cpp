class MagicDictionary {
private:
    set<string> dic;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (auto & word : dictionary) {
            dic.insert(word);
        }
    }
    
    bool search(string searchWord) {
        for (int i = 0; i < searchWord.size(); ++i) {
            int diff = searchWord[i] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (j == diff) {
                    continue;
                }
                char c = 'a' + j;
                string temp = searchWord.substr(0, i) + c + searchWord.substr(i + 1);
                if (dic.count(temp)) {
                    return true;
                }
            } 
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */