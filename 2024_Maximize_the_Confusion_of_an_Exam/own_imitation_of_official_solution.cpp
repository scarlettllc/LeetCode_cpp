class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
    }
    int maxConsecutiveChar(string & answerKey, int k, char ch) {
        int n = answerKey.size(), sum = 0, result = 0;
        for (int left = 0, right = 0; right < n; ++right) {
            sum += (answerKey[right] != ch);
            while (sum > k) {
                if (answerKey[left] != ch) {
                    ++left;
                    --sum;
                } else {
                    ++left;
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};