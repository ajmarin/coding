class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        nums = list(set(nums))
        n = len(nums)
        top = 1 << max(nums).bit_length()
        xor2, xor3 = [False] * top, [False] * top

        for i, a in enumerate(nums):
            for b in nums[i:]:
                xor2[a ^ b] = True

        for a in range(top):
            if xor2[a]:
                for b in nums:
                    xor3[a ^ b] = True
        return sum(xor3)
