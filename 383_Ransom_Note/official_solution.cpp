class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> count(26, 0);
        for (auto & ch : magazine) {
            ++count[ch - 'a'];
        }
        for (auto & ch : ransomNote) {
            --count[ch - 'a'];
            if (count[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};