class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        nums = set(int(n, 2) for n in nums)
        for n in range(1 << len(nums)):
            if n not in nums:
                s = bin(n)[2:]
                return "0" * (len(nums) - len(s)) + s
