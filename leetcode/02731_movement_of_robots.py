class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(nums)
        for i in range(n):
            if s[i] == "R":
                nums[i] += d
            else:
                nums[i] -= d
        nums.sort()
        ans = s = 0
        for i, n in enumerate(nums):
            ans += i * n - s
            s += n
        return ans % (10**9 + 7)
