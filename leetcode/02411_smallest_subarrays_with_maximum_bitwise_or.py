class Solution:
    def smallestSubarrays(self, nums: list[int]) -> list[int]:
        j, n = -1, len(nums)
        ans = [0] * n
        for i in range(n):
            x = nums[i]
            ans[i] = length = 1
            while j >= 0 and nums[j] | x != nums[j]:
                length += 1
                ans[j] = length
                nums[j] |= x
                j -= 1
            j = i
        return ans

