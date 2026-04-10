class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        count, needed = 0, set(range(1, k + 1))
        for n in reversed(nums):
            count += 1
            if n > k:
                continue
            if n in needed:
                needed.remove(n)
                if not needed:
                    return count
