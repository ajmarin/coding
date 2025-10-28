class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        total = sum(nums)
        increment = 2 >> (total & 1)
        goal = {total >> 1, (total + 1) >> 1}
        ans = curr = 0
        for n in nums:
            if n:
                curr += n
            elif curr in goal:
                ans += increment
        return ans
