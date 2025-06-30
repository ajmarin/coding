class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ans = 0
        cnt = Counter(nums)
        for n, c in cnt.items():
            if n + 1 in cnt:
                ans = max(ans, c + cnt[n + 1])
        return ans

