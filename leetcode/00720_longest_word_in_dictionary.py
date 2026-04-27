class Solution:
    def longestWord(self, words: List[str]) -> str:
        seen = set([""])
        words.sort(key=lambda w: (len(w), w))
        ans = ""
        maxlen = 0
        for w in words:
            if w[:-1] in seen:
                seen.add(w)
                if len(w) > maxlen:
                    maxlen = len(w)
                    ans = w
        return ans
