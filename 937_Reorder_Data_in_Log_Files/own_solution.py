class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = []
        digit_logs = []
        for log in logs:
            if (log.split()[1][0].isdigit()):
                digit_logs.append(log)
            else:
                letter_logs.append(log)
        def key_func(log):
            content = ' '.join(log.split()[1:])
            return (content, log.split()[0])
        letter_logs = sorted(letter_logs, key=lambda x:key_func(x))
        letter_logs.extend(digit_logs)
        return letter_logs