class Solution:
    def captureForts(self, forts: List[int]) -> int:
        last_1 = None
        ans = 1
        for i, f in enumerate(forts):
            if f:
                if last_1 is not None and forts[last_1] == -f:
                    ans = i - last_1 if i - last_1 > ans else ans
                last_1 = i
        return ans - 1
