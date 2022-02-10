class Solution {
private:
    vector<set<string>> fractions;
public:
    Solution() {
        fractions.resize(101);
        for (int i = 2; i <= 100; ++i) {
            for (int j = 1; j < i; ++j) {
                int hcf = gcd(i, j);
                if (hcf == 1) {
                    fractions[i].insert(to_string(j) + "/" + to_string(i));
                } else {
                    int i_0 = i / hcf;
                    int j_0 = j / hcf;
                    fractions[i_0].insert(to_string(j_0) + "/" + to_string(i_0));
                }
            }
        }
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for (int i = 2; i <= n; ++i) {
            for (auto & item : fractions[i]) {
                result.push_back(item);
            }
        }
        return result;
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
};