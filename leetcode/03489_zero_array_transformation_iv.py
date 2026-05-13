class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        need = -1
        for i, n in enumerate(nums):
            if n == 0:
                continue
            poss = {0}
            for j, (l, r, v) in enumerate(queries):
                if l <= i <= r:
                    poss |= {p + v for p in poss}
                    if n in poss:
                        break
            else:
                return -1
            need = j if j > need else need
        return need + 1
