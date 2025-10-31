class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        seen = [False] * len(nums)
        for n in nums:
            if seen[n]:
                ans.append(n)
            seen[n] = True
        return ans
