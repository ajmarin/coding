class Solution(object):
    def makesquare(self, nums: List[int]) -> bool:
        nums = list(filter(None, nums))
        if len(nums) < 4 or sum(nums) & 3 or max(nums) > sum(nums) >> 2:
            return False
        def bt(remaining: List[int], index: int) -> bool:
            if index == len(nums):
                return True
            num = nums[index]
            for i, r in enumerate(remaining):
                if num <= r:
                    remaining[i] -= num
                    if bt(remaining, index + 1):
                        return True
                    remaining[i] += num
            return False
        nums.sort(reverse=True)
        return bt([sum(nums) >> 2] * 4, 0)