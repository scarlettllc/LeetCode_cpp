class Solution {
public:
    vector<int> get_real_and_imaginary_part(string num) {
        int a, b;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == '+') {
                a = stoi(num.substr(0, i));
                b = stoi(num.substr(i + 1, num.size() - i - 2));
                return {a, b};
            }
        }
        return {-1, -1};
    }
    string complexNumberMultiply(string num1, string num2) {
        auto temp = get_real_and_imaginary_part(num1);
        int a = temp[0], b = temp[1];
        temp = get_real_and_imaginary_part(num2);
        int c = temp[0], d = temp[1];
        return to_string(a * c - b * d) + '+' + to_string(a * d + b * c) + 'i';
    }
};