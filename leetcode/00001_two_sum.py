class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = {val: index for index, val in enumerate(nums)}
        for i in range(len(nums)):
            x = index.get(target - nums[i])
            if x != i and x is not None:
                return [i, x]
        return [-1, -1]