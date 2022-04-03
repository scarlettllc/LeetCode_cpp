class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters[0] > target || letters[letters.size() - 1] <= target) {
            return letters[0];
        }
        int left = 0, right = letters.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (letters[left] > target) {
            return letters[left];
        } else {
            return letters[0];
        }
    }
};