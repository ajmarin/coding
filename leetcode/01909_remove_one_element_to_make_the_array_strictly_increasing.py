def is_increasing(nums: List[int], ignore: int) -> bool:
    prev = -1
    for i, n in enumerate(nums):
        if i == ignore:
            continue
        if n <= prev:
            return False
        prev = n
    return True


class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        if is_increasing(nums, 0):
            return True
        n = len(nums)
        return any(
            is_increasing(nums, i) or is_increasing(nums, i + 1)
            for i in range(1, n - 1)
            if nums[i] >= nums[i + 1]
        )
