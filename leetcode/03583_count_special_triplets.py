class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        pos = defaultdict(list)
        for i, x in enumerate(nums):
            pos[x].append(i)

        ans = 0
        for i, x in enumerate(nums):
            twox = x << 1
            if len(pos[twox]) > 1:
                idx = bisect_left(pos[twox], i)
                ans += idx * (len(pos[twox]) - idx - (x == 0))
        return ans % (10**9 + 7)
