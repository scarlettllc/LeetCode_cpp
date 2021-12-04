class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count_ransomNote(26, 0);
        vector<int> count_magazine(26, 0);
        for (auto & ch : ransomNote) {
            ++count_ransomNote[ch - 'a'];
        }
        for (auto & ch : magazine) {
            ++count_magazine[ch - 'a'];
        }
        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (count_ransomNote[i] > count_magazine[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};