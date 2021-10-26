struct Trie {
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }
};
void insert(Trie* trie, string word) {
    Trie* node = trie;
    for (auto & ch : word) {
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            node->children[ch] = new Trie();
        }
        node = node->children[ch];
    }
    node->isEnd = true;
}
bool dfs(string word, int index, Trie* node) {
    if (index == word.size()) {
        return node->isEnd;
    }
    char ch = word[index];
    if (ch != '.') {
        ch -= 'a';
        if (node->children[ch] != nullptr && dfs(word, index + 1, node->children[ch])) {
            return true;
        }
    } else {
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr && dfs(word, index + 1, node->children[i])) {
                return true;
            }
        }
    }
    return false;
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
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */