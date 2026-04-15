class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        c = Counter(nums)
        if len(set(c.values())) == 1:
            return [-1, -1]
        k = sorted(c.keys())
        for i, n1 in enumerate(k):
            for n2 in k[i + 1 :]:
                if c[n1] != c[n2]:
                    return [n1, n2]
