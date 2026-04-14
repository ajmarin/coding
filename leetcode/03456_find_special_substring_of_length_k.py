class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        prev = cnt = 0
        for c in s:
            if c != prev:
                if cnt == k:
                    break
                cnt = 1
            else:
                cnt += 1
            prev = c
        return cnt == k
