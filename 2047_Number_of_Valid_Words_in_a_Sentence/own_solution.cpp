class Solution {
public:
    int countValidWords(string sentence) {
        vector<string> candidates;
        int i = 0, j, n = sentence.size();
        while (i < n) {
            if (sentence[i] == ' ') {
                ++i;
                continue;
            } else {
                j = i;
                while (j < n && sentence[j] != ' ') {
                    ++j;
                }
                candidates.push_back(sentence.substr(i, j - i));
                i = j;
            }
        }
        int result = 0, len, count;
        bool flag;
        for (auto & candidate : candidates) {
            flag = true;
            len = candidate.size();
            count = 0;
            for (int k = 0; k < len; ++k) {
                if (candidate[k] >= '0' && candidate[k] <= '9') {
                    flag = false;
                    break;
                }
                if ((candidate[k] == '!' || candidate[k] == '.' || candidate[k] == ',') && k != len - 1) {
                    flag = false;
                    break;
                }
                if (candidate[k] == '-') {
                    ++count;
                    if (count > 1) {
                        flag = false;
                        break;
                    }
                    if (len < 3) {
                        flag = false;
                        break;
                    }
                    if (k == 0 || k == len - 1) {
                        flag = false;
                        break;
                    }
                    if (k == len - 2 && (candidate[k + 1] == '!' || candidate[k + 1] == '.' || candidate[k + 1] == ',')) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                ++result;
            }
        }
        return result;
    }
};