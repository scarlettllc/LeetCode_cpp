class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag1, flag2;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            flag1 = true;
        } else {
            flag1 = false;
        }
        if (word.size() > 1 && word[1] >= 'A' && word[1] <= 'Z') {
            flag2 = true;
        }else {
            flag2 = false;
        }
        if (!flag1 && flag2) {
            return false;
        }
        for (int i = 2; i < word.size(); ++i) {
            if (flag1 && flag2 && word[i] >= 'a' && word[i] <= 'z') {
                return false;
            } else if (flag1 && !flag2 && word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            } else if (!flag1 && !flag2 && word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
        return true;
    }
};