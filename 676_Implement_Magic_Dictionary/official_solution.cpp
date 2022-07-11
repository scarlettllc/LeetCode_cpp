class MagicDictionary {
private:
    vector<string> words;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for (auto & word : words) {
            if (searchWord.size() != word.size()) {
                continue;
            }
            int diff = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (searchWord[i] != word[i]) {
                    ++diff;
                }
            }
            if (diff == 1) {
                return true;
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