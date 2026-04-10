class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        prev = 10**6
        ans, curr, wanted = -1, 0, 1
        for n in nums:
            if n - prev == wanted:
                wanted = -wanted
                curr += 1
                ans = curr if curr > ans else ans
            else:
                curr = n - prev == 1
                wanted = 1 if curr == 0 else -1
            prev = n
        return ans + (ans != -1)
