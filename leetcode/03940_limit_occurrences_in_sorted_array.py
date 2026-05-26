class Solution:
    def limitOccurrences(self, nums: list[int], k: int) -> list[int]:
        prev, cnt = -1, 0
        ans = []
        for n in nums:
            if n != prev:
                prev = n
                cnt = 0
            cnt += 1
            if cnt <= k:
                ans.append(n)
        return ans
