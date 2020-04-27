class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def process(s: str):
            r = []
            for c in s:
                if c != '#':
                    r.append(c)
                elif r:
                    r.pop()
            return ''.join(r)
        return process(S) == process(T)