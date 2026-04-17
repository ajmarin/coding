class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        if sum(nums) == 0:
            return "0"
        return "".join(sorted(map(str, nums), key=lambda s: 10 * s, reverse=True))
