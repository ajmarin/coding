class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        L, W = len(words[0]), len(words)
        count = collections.Counter(words)
        def check(s: str, start: str):
            top = 0
            ws = [None] * W
            for i in range(start, len(s), L):
                w = s[i:i+L]
                if not count[w]:
                    break
                count[w] -= 1
                ws[top] = w
                top = top + 1
                if top == W:
                    break
            for w in ws[:top]:
                count[w] += 1
            return top == W
        return list(filter(lambda i: check(s, i), range(len(s) - L * W + 1)))