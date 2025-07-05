class Solution:
    def findLucky(self, arr: List[int]) -> int:
        c = Counter(arr)
        return max((k for k in c if c[k] == k), default=-1)

