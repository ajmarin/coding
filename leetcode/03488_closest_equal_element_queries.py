class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        pos = defaultdict(list)
        N = len(nums)
        for i, n in enumerate(nums):
            pos[n].append(i)
        ans = []
        for q in queries:
            n = nums[q]
            npos = pos[n]
            l = len(npos)
            if l == 1:
                ans.append(-1)
                continue
            i = bisect_left(npos, q)
            res = inf
            for d in (l - 1, 1):
                j = (i + d) % l
                dist = abs(npos[j] - q)
                dist = dist if dist < N - dist else N - dist
                res = res if res < dist else dist
            ans.append(res)
        return ans
