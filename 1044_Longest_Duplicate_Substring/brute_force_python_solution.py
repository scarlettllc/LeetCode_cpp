class Solution:
    def longestDupSubstring(self, s: str) -> str:
        result = ""
        for i in range(len(s)):
            while s[i : i + len(result) + 1] in s[i + 1 :]:
                result = s[i : i + len(result) + 1]
        return result