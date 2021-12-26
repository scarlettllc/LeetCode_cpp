class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> string_list;
        int i = 0;
        while (i < text.size()) {
            int j = i;
            while (j < text.size() && text[j] != ' ') {
                ++j;
            }
            string_list.push_back(text.substr(i, j - i));
            i = j + 1;
        }
        vector<string> result;
        for (int i = 2; i < string_list.size(); ++i) {
            if (string_list[i - 2] == first && string_list[i - 1] == second) {
                result.push_back(string_list[i]);
            }
        }
        return result;
    }
};