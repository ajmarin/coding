class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        N = len(nums)

        best = 0
        for n in nums: best |= n

        def bt(i, curr):
            if i == N: return curr == best
            return bt(i + 1, curr) + bt(i + 1, curr | nums[i])

        return bt(0, 0)

