class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        last = {}
        for i, n in enumerate(nums):
            if i - last.get(n, -(10**6)) <= k:
                return True
            last[n] = i
        return False
