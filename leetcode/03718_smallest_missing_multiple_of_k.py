class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        has = [False] * 201
        for n in nums:
            has[n] = True
        return next(n for n in range(k, 1000, k) if not has[n])
