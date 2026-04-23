class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        first = {}
        curr = 0
        for i, n in enumerate(nums):
            curr = (curr + n) % k
            if i and not curr:
                return True
            if curr not in first:
                first[curr] = i
                continue
            if i - first[curr] > 1:
                return True
        return False
