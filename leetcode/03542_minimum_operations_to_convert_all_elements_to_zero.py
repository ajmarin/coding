stack = [-1] * 100001


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = pos = 0
        for n in nums:
            if not n:
                pos = 0
                continue
            while stack[pos] > n:
                pos -= 1
            if stack[pos] < n:
                ans += 1
                stack[(pos := pos + 1)] = n
        return ans
