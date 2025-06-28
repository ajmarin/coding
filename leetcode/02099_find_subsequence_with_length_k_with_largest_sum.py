class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        answer = sorted(enumerate(nums), key=lambda x: x[1])[-k:]
        return list(map(lambda v: v[1], sorted(answer)))

