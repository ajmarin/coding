class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        highest, n = max(nums), len(nums)
        ans = 0
        for a, numa in enumerate(nums):
            for b in range(a + 1, n):
                total = numa + nums[b]
                if total > highest:
                    continue
                for c in range(b + 1, n):
                    totalc = total + nums[c]
                    if totalc > highest:
                        continue
                    for d in range(c + 1, n):
                        ans += nums[d] == totalc
        return ans
