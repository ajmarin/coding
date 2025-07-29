class Solution:
    def maxJump(self, s: List[int]) -> int:
        ita, itb = iter(s), iter(s[1:])
        ans = next(itb) - s[0]
        for s in itb:
            cand = s - next(ita)
            ans = cand if cand > ans else ans
        return ans

