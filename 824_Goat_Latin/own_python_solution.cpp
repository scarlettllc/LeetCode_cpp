class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        result_list = []
        word_list = sentence.split()
        for idx, word in enumerate(word_list):
            idx += 1
            if word[0].lower() in {'a', 'e', 'i', 'o', 'u'}:
                word = word + 'ma'
            else:
                word = word[1:] + word[0] + 'ma'
            for i in range(idx):
                word += 'a'
            result_list.append(word)
        return ' '.join(result_list)