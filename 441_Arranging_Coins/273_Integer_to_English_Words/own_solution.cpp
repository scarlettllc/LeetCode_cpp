class Solution {
public:
    string hundredsToWords(string num) {
        if (num == "") {
            return "";
        }
        unordered_map<char, string> digit2num{{'1', "One"},{'2', "Two"}, {'3', "Three"}, {'4', "Four"}, {'5', "Five"}, {'6', "Six"}, {'7', "Seven"}, {'8', "Eight"}, {'9', "Nine"}};
        unordered_map<string, string> digit2_teens{{"10", "Ten"}, {"11", "Eleven"}, {"12", "Twelve"}, {"13", "Thirteen"}, {"14", "Fourteen"}, {"15", "Fifteen"}, {"16", "Sixteen"}, {"17", "Seventeen"}, {"18", "Eighteen"}, {"19", "Nineteen"}};
        unordered_map<char, string> digits2_tens{{'2', "Twenty"}, {'3', "Thirty"}, {'4', "Forty"}, {'5', "Fifty"}, {'6', "Sixty"}, {'7', "Seventy"}, {'8', "Eighty"}, {'9', "Ninety"}};
         string result = "";
         if (num.size() == 1) {
             return digit2num[num[0]];
         }
         if (num.size() == 2) {
             if (num[0] == '1') {
                 return digit2_teens[num];
             } else {
                 result += digits2_tens[num[0]];
                 if (num[1] != '0') {
                     result += " ";
                     result += digit2num[num[1]];
                 }
             }
         }
         if (num.size() == 3) {
             result += digit2num[num[0]] + " Hundred";
             if (num.substr(1) == "00") {
                return result;
            }
            if (num[1] == '0') {
                result += " ";
                result += digit2num[num[2]];
            } else {
                result += " ";
                result += hundredsToWords(num.substr(1));
            }
         }
         return result;
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string num_str = to_string(num);
        string tail = "";
        string thousand = "";
        string million = "";
        string billion = "";
        while (num_str.size() % 3 != 0) {
            num_str = "0" + num_str;
        }
        if (num_str.size() == 3) {
            tail = num_str;
        } else if (num_str.size() == 6) {
            tail = num_str.substr(3, 3);
            thousand = num_str.substr(0, 3);
        } else if (num_str.size() == 9) {
            tail = num_str.substr(6, 3);
            thousand = num_str.substr(3, 3);
            million = num_str.substr(0, 3);
        } else {
            tail = num_str.substr(9, 3);
            thousand = num_str.substr(6, 3);
            million = num_str.substr(3, 3);
            billion = num_str.substr(0, 3);
        }
        while (tail[0] == '0') {
            tail = tail.substr(1);
        }
        while (thousand[0] == '0') {
            thousand = thousand.substr(1);
        }
        while (million[0] == '0') {
            million = million.substr(1);
        }
        while (billion[0] == '0') {
            billion = billion.substr(1);
        }
        string result = "";
        if (billion != "") {
            result += hundredsToWords(billion) + " Billion";
        }
        if (million != "") {
            if (billion != "") {
                result += " ";
            }
            result += hundredsToWords(million) + " Million";
        }
        if (thousand != "") {
            if (billion != "" || million != "") {
                result += " ";
            }
            result += hundredsToWords(thousand) + " Thousand";
        }
        if (tail != "") {
            if (billion != "" || million != "" || thousand != "") {
                result += " ";
            }
            result += hundredsToWords(tail);
        }
        return result;
    }
};