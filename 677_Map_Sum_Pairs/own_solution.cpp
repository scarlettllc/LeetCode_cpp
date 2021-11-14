struct Trie {
    vector<Trie*> children;
    int val;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->val = 0;
    }
};
Trie* search(Trie* trie, string prefix) {
    Trie* node = trie;
    for (auto & ch : prefix) {
        if (node->children[ch - 'a'] == nullptr) {
            return nullptr;
        }
        node = node->children[ch - 'a'];
    }
    return node;
}
int dfs(Trie* node) {
    int result = node->val;
    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != nullptr) {
            result += dfs(node->children[i]);
        }
    }
    return result;
}

class MapSum {
private:
    Trie* trie;
public:
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        Trie* node = trie;
        for (auto & ch : key) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->val = val;
    }
    int sum(string prefix) {
        Trie* node = search(trie, prefix);
        if (node == nullptr) {
            return 0;
        } else {
            return dfs(node);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */