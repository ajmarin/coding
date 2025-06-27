class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return -1 if k > min(nums) \
                else len([c for c in Counter(nums) if c > k])

