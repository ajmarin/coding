class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        cost = 1
        prev = -1
        for n in nums[::-1] + [1]:
            if n == 1:
                if prev == 0:
                    ans += cost
                cost = 2
            prev = n
        return ans
