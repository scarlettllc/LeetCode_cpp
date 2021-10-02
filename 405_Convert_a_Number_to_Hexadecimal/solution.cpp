class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        if (num == -2147483648) {
            return "80000000";
        }
        string binary = "";
        if (num > 0) {
            while (num) {
                binary = to_string(num % 2) + binary;
                num = num / 2;
            }
        } else {
            int abs_num = abs(num);
            string temp = "";
            while (abs_num) {
                temp = to_string(abs_num % 2) + temp;
                abs_num = abs_num / 2;
            }
            while (temp.size() < 32) {
                temp = '0' + temp;
            }
            for (int i = 0; i < 32; ++i) {
                binary += to_string(1 - (temp[i] - '0'));
            }
            for (int i = 31; i >= 0; --i) {
                if (binary[i] == '0') {
                    binary[i] = '1';
                    for (int j = i + 1; j < 32; ++j) {
                        binary[j] = '0';
                    }
                    break;
                }
            }
        }
        if (binary[0] == '0') {
            binary = binary.substr(1);
        }
        int len = binary.size();
        if (len % 4) {
            while (len % 4) {
                binary = '0' + binary;
                len += 1;
            }
        }
        string result = "";
        for (int i = 0; i < len; i += 4) {
            int temp = (binary[i] - '0') * 8 + (binary[i + 1] - '0') * 4 + (binary[i + 2] - '0') * 2 + (binary[i + 3] - '0'); 
            if (temp < 10) {
                result += to_string(temp);
            } else {
                switch(temp) {
                    case 10: result += 'a'; break;
                    case 11: result += 'b'; break;
                    case 12: result += 'c'; break;
                    case 13: result += 'd'; break;
                    case 14: result += 'e'; break;
                    case 15: result += 'f'; break;
                }
            }
        }
        return result;
    }
};