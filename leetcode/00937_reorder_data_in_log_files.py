class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        dig, let = [], []
        for log in logs:
            ident, words = log.split(' ', maxsplit=1)
            if all(w.isdigit() for w in words.split(' ')):
                dig.append(log)
            else:
                let.append((words, ident))
        return [f'{ident} {words}' for words, ident in sorted(let)] + list(dig)