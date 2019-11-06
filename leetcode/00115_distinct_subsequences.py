import functools
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @functools.lru_cache(None)
        def bt(idx: int, tidx: int) -> int:
            if tidx == len(t):
                return 1
            if idx == len(s):
                return 0
            answer = 0
            for i in range(idx, len(s)):
                if s[i] == t[tidx]:
                    answer += bt(i + 1, tidx + 1)
            return answer
        return bt(0, 0)