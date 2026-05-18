class Solution:
    def minRemovals(self, nums: List[int], target: int) -> int:
        removals = {0: len(nums)}
        for x in nums:
            updated = {x ^ y: cost - 1 for y, cost in removals.items()}
            for n, c in updated.items():
                removals[n] = min(removals.get(n, c), c)
        return removals.get(target, -1)
