class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        max_count = 0
        for index in range(len(nums)):
            count = 0
            while nums[index] is not None:
                tmp = nums[index]
                nums[index] = None
                index = tmp
                count += 1
            max_count = max(max_count, count)
        return max_count