class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m{{'q',0},{'w',0},{'e',0},{'r',0},{'t',0}, \
          {'y',0},{'u',0},{'i',0},{'o',0},{'p',0},{'a',1},{'s',1},{'d',1},\
          {'f',1},{'g',1},{'h',1},{'j',1},{'k',1},{'l',1},{'z',2},{'x',2},{'c',2},\
          {'v',2},{'b',2},{'n',2},{'m',2}};
        vector<string> result;
        for (auto & word : words) {
            bool flag = true;
            set<int> s;
            for (auto & ch : word) {
                if (ch >= 'a' && ch <= 'z') {
                    if (!s.count(m[ch])) {
                        s.insert(m[ch]);
                    }
                    if (s.size() > 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if (!s.count(m[ch - 'A' + 'a'])) {
                        s.insert(m[ch - 'A' + 'a']);
                    }
                    if (s.size() > 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                result.push_back(word);
            }
        }
        return result;
    }
};