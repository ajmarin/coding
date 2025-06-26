class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        count = 0
        for left, num in enumerate(nums):
            r = num
            for right in range(left, len(nums)):
                r = gcd(r, nums[right])
                if r < k:
                    break
                count += r == k
        return count

