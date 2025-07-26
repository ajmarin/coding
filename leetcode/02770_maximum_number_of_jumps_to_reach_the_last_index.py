class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if abs(nums[-1] - nums[0]) > target * (n - 1): return -1
        hops = [-1] * n
        hops[0] = 0
        for i in range(n):
            cand = hops[i] + 1
            if not cand: continue
            ni = nums[i]
            for j in range(i + 1, n):
                if hops[j] < cand and abs(nums[j] - ni) <= target:
                    hops[j] = cand
        return hops[-1]

