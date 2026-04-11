class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        prev2 = {}
        ans = 1 << 20
        for k, n in enumerate(nums):
            if n in prev2:
                mask = prev2[n]
                i = mask & 0xFFFFF
                if i:
                    dist = k - i
                    ans = dist if dist < ans else ans
                prev2[n] = ((k + 1) << 20) | (mask >> 20)
            else:
                prev2[n] = (k + 1) << 20
        return -(ans == 1 << 20) | (1 + ans) << 1
