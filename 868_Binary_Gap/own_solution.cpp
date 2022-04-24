class Solution {
public:
    int binaryGap(int n) {
        vector<int> binary_repre = get_binary_repre(n);
        int result = 0, m = binary_repre.size();
        for (int i = 0; i < m; ++i) {
            if (binary_repre[i] == 1) {
                if (i + 1 < m && binary_repre[i + 1] == 1) {
                    result = max(result, 1);
                } else {
                    int j = i + 1;
                    while (j < m && binary_repre[j] == 0) {
                        ++j;
                    }
                    if (j < m) {
                        result = max(result, j - i);
                    } 
                }
            }
        }
        return result;
    }
    vector<int> get_binary_repre(int n) {
        vector<int> result;
        while (n) {
            result.push_back(n % 2);
            n /= 2;
        }
        return result;
    }
};