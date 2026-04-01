class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        cnt, n = Counter(arr), len(arr) / 4
        return next(x for x in cnt if cnt[x] > n)
