class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        seen = [False] * 100
        ans = 0
        for n in nums:
            if seen[n]:
                ans ^= n
            else:
                seen[n] = True
        return ans
