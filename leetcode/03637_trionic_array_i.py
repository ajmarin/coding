class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        N = len(nums)
        prev = nums[0]
        p = 1
        while p < N and nums[p] > prev:
            prev = nums[p]
            p += 1
        q = p
        p -= 1
        while q < N and nums[q] < prev:
            prev = nums[q]
            q += 1
        r = q
        q -= 1
        while r < N and nums[r] > prev:
            prev = nums[r]
            r += 1
        r -= 1
        return 0 < p < q < r == N - 1

