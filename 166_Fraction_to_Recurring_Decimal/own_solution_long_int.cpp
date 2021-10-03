class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        long int numerator = (long int) num;
        long int denominator = (long int) deno;
        if (numerator == 0) {
            return "0";
        }
        bool flag1 = true;
        if (numerator < 0) {
            flag1 = false;
            numerator = -numerator;
        }
        bool flag2 = true;
        if (denominator < 0) {
            denominator = -denominator;
            flag2 = false;
        }
        long int quotient = numerator / denominator;
        long int remainder = numerator % denominator;
        if (remainder == 0) {
            string result = to_string(quotient);
            if (flag1 == flag2) {
                if (result[0] == '-') {
                    return result.substr(1);
                } else {
                    return result;
                }
            } else {
                if (result[0] == '-') {
                    return result;
                } else {
                    return "-" + result;
                }
            }
        }
        string result = "";
        result += to_string(quotient);
        result += ".";
        unordered_map<long int, vector<long int>> remainder_seq_quotient;
        long int seq = 0;
        while (remainder) {
            remainder = (remainder << 3) + (remainder << 1);
            quotient = remainder / denominator;
            seq += 1;
            if (remainder_seq_quotient.find(remainder) == remainder_seq_quotient.end()) {
                vector<long int> temp;
                temp.emplace_back(seq);
                temp.emplace_back(quotient);
                remainder_seq_quotient.insert(make_pair(remainder, temp));
                result += to_string(quotient);
                remainder = remainder % denominator;
            } else {
                vector<long int> temp = remainder_seq_quotient[remainder];
                long int seq = temp[0];
                result.append(")");
                long int point_pos = result.find('.');
                result = result.substr(0, point_pos + seq) + "(" + result.substr(point_pos + seq);
                break;
            }
        }
        if (flag1 == flag2) {
            if (result[0] == '-') {
                return result.substr(1);
            } else {
                return result;
            }
        } else {
            if (result[0] == '-') {
                return result;
            } else {
                return "-" + result;
            }
        }
    }
};