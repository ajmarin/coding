class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        for length in range(1, n + 1):
            for i in range(n - length + 1):
                res = 0
                for j in range(i, i + length):
                    res |= nums[j]
                if res >= k:
                    return length
        return -1
