class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        unordered_map<char, int> temp1, temp2;
        int n = secret.size();
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++a;
            } else {
                ++temp1[secret[i]];
                ++temp2[guess[i]];
            }
        }
        unordered_map<char, int>::iterator it;
        for (it = temp1.begin(); it != temp1.end(); ++it) {
            if (temp2.find(it->first) != temp2.end()) {
                b += min(temp1[it->first], temp2[it->first]);
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};