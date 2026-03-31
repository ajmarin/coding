class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        cnt = Counter(words[0])
        for w in words:
            cnt &= Counter(w)
        ans = []
        for c, times in cnt.items():
            ans.extend([c] * times)
        return ans
