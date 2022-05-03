class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string& log1, const string& log2){
            int pos1 = log1.find(' '), pos2 = log2.find(' ');
            bool isdigit1 = isdigit(log1[pos1 + 1]);
            bool isdigit2 = isdigit(log2[pos2 + 1]);
            if (isdigit1 && isdigit2) {
                return false;
            }
            if (!isdigit1 && !isdigit2) {
                string s1 = log1.substr(pos1 + 1);
                string s2 = log2.substr(pos2 + 1);
                if (s1 != s2) {
                    return s1 < s2;
                } 
                return log1 < log2;
            }
            return isdigit1? false: true;
        }); 
        return logs;
    }
};