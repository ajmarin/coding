class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        alternating = odds = 0
        wanted_parity = nums[0] & 1
        for n in nums:
            parity = n & 1
            odds += parity
            if parity == wanted_parity:
                wanted_parity ^= 1
                alternating += 1
        return max(odds, len(nums) - odds, alternating)

