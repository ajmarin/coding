class Solution:
    def minCost(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        n = len(nums)
        closest = [1] + [0] * (n - 2) + [n - 2]
        dprev = nums[1] - nums[0]
        for i in range(1, n - 1):
            dnext = nums[i + 1] - nums[i]
            closest[i] = i - 1 if dprev <= dnext else i + 1
            dprev = dnext

        left, right = [0] * n, [0] * n
        for a, b in pairwise(range(n)):
            right[b] = right[a] + (1 if closest[a] == b else nums[b] - nums[a])
        for a, b in pairwise(reversed(range(n))):
            left[b] = left[a] + (1 if closest[a] == b else nums[a] - nums[b])
        return [right[t] - right[f] if t > f else left[t] - left[f] for f, t in queries]
