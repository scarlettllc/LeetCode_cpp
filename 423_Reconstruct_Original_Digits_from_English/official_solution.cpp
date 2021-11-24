class Solution {
public:
    string originalDigits(string s) {
        vector<int> word_map(26, 0);
        for (auto & ch : s) {
            ++word_map[ch-'a'];
        }
        vector<int> numbers(10, -1);
        numbers[0] = word_map['z'-'a'];
        numbers[2] = word_map['w'-'a'];
        numbers[4] = word_map['u'-'a'];
        numbers[6] = word_map['x'-'a'];
        numbers[8] = word_map['g'-'a'];
        numbers[3] = word_map['h'-'a'] - numbers[8];
        numbers[7] = word_map['s'-'a'] - numbers[6];
        numbers[5] = word_map['v'-'a'] - numbers[7];
        numbers[1] = word_map['o'-'a'] - numbers[0] - numbers[2] - numbers[4];
        numbers[9] = word_map['i'-'a'] - numbers[5] - numbers[6] - numbers[8];

        string result = "";
        for (int i = 0; i < 10; ++i) {
            if (numbers[i] > 0) {
                string temp_str(numbers[i], to_string(i)[0]);
                result += temp_str;
            }
        }
        return result;
        /*
        unordered_map<char, int> word_map;
        for (auto & ch : s) {
            ++word_map[ch];
        }
        vector<int> numbers(10, -1);
        numbers[0] = word_map['z'];
        numbers[2] = word_map['w'];
        numbers[4] = word_map['u'];
        numbers[6] = word_map['x'];
        numbers[8] = word_map['g'];
        numbers[3] = word_map['h'] - numbers[8];
        numbers[7] = word_map['s'] - numbers[6];
        numbers[5] = word_map['v'] - numbers[7];
        numbers[1] = word_map['o'] - numbers[0] - numbers[2] - numbers[4];
        numbers[9] = word_map['i'] - numbers[5] - numbers[6] - numbers[8];

        string result = "";
        for (int i = 0; i < 10; ++i) {
            if (numbers[i] > 0) {
                string temp_str(numbers[i], to_string(i)[0]);
                result += temp_str;
            }
        }
        return result;
        */
        /*
        zero one two three four five six seven eight nine
        x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9

        word_map['e'] = x_0 + x_1 + 2 * x_3 + x_5 + 2 * x_7 + x_8 + x_9;
        word_map['g'] = x_8;
        word_map['f'] = x_4 + x_5;
        word_map['i'] = x_5 + x_6 + x_8 + x_9;
        word_map['h'] = x_3 + x_8;
        word_map['o'] = x_0 + x_1 + x_2 + x_4;
        word_map['n'] = x_1 + x_7 + 2 * x_9;
        word_map['s'] = x_6 + x_7;
        word_map['r'] = x_0 + x_3 + x_4;
        word_map['u'] = x_4;
        word_map['t'] = x_2 + x_3 + x_8;
        word_map['w'] = x_2;
        word_map['v'] = x_5 + x_7;
        word_map['x'] = x_6;
        word_map['z'] = x_0;

        word_map['f'] = 2 = x_4 + x_5;
        word_map['i'] = 1 = x_5 + x_6 + x_8 + x_9;
        word_map['v'] = 1 = x_5 + x_7;
        word_map['e'] = 1 = x_0 + x_1 + 2 * x_3 + x_5 + 2 * x_7 + x_8 + x_9;
        word_map['o'] = 1 = x_0 + x_1 + x_2 + x_4;
        word_map['u'] = 1 = x_4;
        word_map['r'] = 1 = x_0 + x_3 + x_4;
        int len=4*x_0+3*x_1+3*x_2+5*x_3+4*x_4+4*x_5+3*x_6+5*x_7+5*x_8+4*x_9;
        x_i >= 0;
        */
    }
};