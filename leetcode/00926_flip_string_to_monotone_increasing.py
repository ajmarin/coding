class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        ones = s.count("1")
        ans = min(ones, n - ones)
        cand = n - ones
        for c in s:
            cand += (c == "1") - (c == "0")
            ans = ans if ans < cand else cand
        return ans
