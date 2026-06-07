class Solution:
    def checkEqualPartitions(self, nums: List[int], target: int) -> bool:
        total = 1
        for n in nums:
            total *= n
        if total != target * target:
            return False

        def bt(i: int, p: int) -> bool:
            if p == target:
                return True
            if p > target or i == len(nums):
                return False
            return bt(i + 1, p * nums[i]) or bt(i + 1, p)

        return bt(0, 1)
