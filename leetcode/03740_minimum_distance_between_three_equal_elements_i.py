class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        prev = [0] * (n + 1)
        ans = 10_000

        for i in range(n):
            num = nums[i]
            previous = prev[num]
            two_b4 = previous & 0xFF
            if two_b4:
                dist = i + 1 - two_b4
                ans = dist if dist < ans else ans
            prev[num] = ((i + 1) << 8) | (previous >> 8)

        return ans << 1 if ans != 10_000 else -1
