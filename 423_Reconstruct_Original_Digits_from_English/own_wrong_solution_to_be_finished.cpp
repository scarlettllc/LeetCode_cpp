class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> word_map{
            {'e', 0}, {'g', 0}, {'f', 0}, {'i', 0}, {'h', 0}, {'o', 0},
            {'n', 0}, {'s', 0}, {'r', 0}, {'u', 0}, {'t', 0}, {'w', 0},
            {'v', 0}, {'x', 0}, {'z', 0}
        };
        for (auto & ch : s) {
            ++word_map[ch];
        }
        vector<int> numbers(10, -1);
        unordered_map<char, vector<int>> word2number{
            {'e', {0, 1, 3, 5, 7, 8, 9}}, {'g', {8}}, {'f', {4, 5}},
            {'i', {5, 6, 8, 9}}, {'h', {3, 8}}, {'o', {0, 1, 2, 4}},
            {'n', {1, 7, 9}}, {'s', {6, 7}}, {'r', {0, 3, 4}}, {'u', {4}},
            {'t', {2, 3, 8}}, {'w', {2}}, {'v', {5, 7}}, {'x', {6}}, {'z', {0}}
        };
        unordered_map<char, int>::iterator it;
        for (it = word_map.begin(); it != word_map.end(); ++it) {
            if (word_map[it->first] == 0) {
                vector<int> temp = word2number[it->first];
                for (int i = 0; i < temp.size(); ++i) {
                    numbers[temp[i]] = 0;
                }
            }
        }
        string result = "";
        for (int i = 0; i < 10; ++i) {
            if (numbers[i] > 0) {
                string temp_str(numbers[i], to_string(i)[0]);
                result += temp_str;
            }
        }
        return result;
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