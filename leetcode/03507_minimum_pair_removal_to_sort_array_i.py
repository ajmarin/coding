class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        ans = 0
        while True:
            ascending = True
            index, min_sum = -1, inf
            for i, (a, b) in enumerate(pairwise(nums)):
                ascending &= a <= b
                if a + b < min_sum:
                    min_sum = a + b
                    index = i
            if ascending:
                break
            nums[index] = min_sum
            nums.pop(index + 1)
            ans += 1
        return ans
