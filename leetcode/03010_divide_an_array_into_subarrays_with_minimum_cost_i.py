class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        lowest, second = inf, inf
        for n in nums[1:]:
            if n < lowest:
                lowest, second = n, lowest
            elif n < second:
                second = n
        return nums[0] + lowest + second
