class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        rem = 0
        for n in nums:
            rem = (rem << 1) + n
            rem %= 5
            ans.append(rem == 0)
        return ans
