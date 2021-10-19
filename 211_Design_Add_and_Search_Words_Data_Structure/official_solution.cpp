struct Trie {
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }
};
void insert(Trie* root, const string& word) {
    Trie* node = root;
    for (char ch : word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            node->children[ch] = new Trie();
        }
        node = node->children[ch];
    }
    node->isEnd = true;
}
class WordDictionary {
private:
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        insert(trie, word);
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string& word, int index, Trie* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            Trie* child = node->children[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            } 
        } else if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                Trie* child = node->children[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
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