class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        last_even, n = -1, len(nums)
        for i in range(n):
            if not (nums[i] & 1):
                continue
            for j in range(max(i + 1, last_even), n):
                if not nums[j] & 1:
                    nums[i], nums[j] = nums[j], nums[i]
                    last_even = j
                    break
            else:
                break
        return nums
