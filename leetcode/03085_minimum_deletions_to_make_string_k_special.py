import collections

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        ans = len(word)
        cnt = collections.Counter(word)
        for c, n in cnt.items():
            upper = n + k
            candidate = 0
            for v in cnt.values():
                candidate += v if v < n else max(v - upper, 0)
            ans = min(ans, candidate)
        return ans

