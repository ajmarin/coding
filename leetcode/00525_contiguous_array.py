class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        L = len(nums)
        pos = [None] * (2 * L + 1)
        pos[L] = -1
        balance, max_len = 0, 0
        for i, n in enumerate(nums):
            balance += 1 if n else -1
            p = balance + L
            posp = pos[p]
            if posp is None:
                pos[p] = i
            else:
                max_len = max(max_len, i - posp)
        return max_len