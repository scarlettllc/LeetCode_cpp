class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def key_func(log):
            a, b = log.split(' ', 1)
            return (0, b, a) if b[0].isalpha() else (1,)
        logs.sort(key = key_func)
        return logs