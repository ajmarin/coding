class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        return [
            len(set(nums[: i + 1])) - len(set(nums[i + 1 :])) for i in range(len(nums))
        ]
