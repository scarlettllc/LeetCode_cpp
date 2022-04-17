class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.replace('!', ' ').replace('?', ' ').replace("'", ' ')\
        .replace(',', ' ').replace(';', ' ').replace('.', ' ').lower()
        words = paragraph.split()
        count_dict = {}
        result = ''
        count = 0
        for word in words:
            if word in banned:
                continue
            if word not in count_dict:
                count_dict[word] = 0
            count_dict[word] += 1
            if count_dict[word] > count:
                result = word
                count = count_dict[word]
        return result