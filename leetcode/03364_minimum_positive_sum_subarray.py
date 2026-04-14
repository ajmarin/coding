class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        l -= 1
        ans = inf
        for start in range(n):
            total = 0
            for pos in range(start, min(start + r, n)):
                total += nums[pos]
                if total > 0 and pos - start >= l:
                    ans = min(total, ans)
        return ans if ans != inf else -1
