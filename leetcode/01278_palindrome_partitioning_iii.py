import functools
class Solution:
    @functools.lru_cache(None)
    def fix(self, s: str) -> int:
        return sum(s[i] != s[~i] for i in range(len(s) // 2))

    @functools.lru_cache(None)
    def palindromePartition(self, s: str, k: int) -> int:
        if k == 1:
            return self.fix(s)
        if k == len(s):
            return 0
        answer = len(s)
        for i in range(1, len(s) - k + 2):
            answer = min(answer, self.fix(s[:i]) + self.palindromePartition(s[i:], k - 1))
        return answer