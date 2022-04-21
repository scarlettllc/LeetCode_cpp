class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> result_list;
        int i = 0, n = sentence.size();
        string temp = "";
        for (int i = 0; i < n; ++i) {
            if (sentence[i] == ' ') {
                continue;
            }
            while (i < n && sentence[i] != ' ') {
                temp += sentence[i];
                ++i;
            }
            int idx = result_list.size() + 1;
            if (tolower(temp[0]) == 'a' || tolower(temp[0]) == 'e' 
            || tolower(temp[0]) == 'i' || tolower(temp[0]) == 'o' || tolower(temp[0]) == 'u') {
                temp = temp + "ma";
            } else {
                temp = temp.substr(1) + temp[0] + "ma";
            }
            for (int j = 0; j < idx; ++j) {
                temp += 'a';
            } 
            result_list.push_back(temp);
            temp = "";
        }
        string result = "";
        for (int i = 0; i < result_list.size(); ++i) {
            if (i == 0) {
                result += result_list[i];
            } else {
                result += ' ';
                result += result_list[i];
            }
        }
        return result;
    }
};