class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        s = set(arr)
        ans = 0

        for a, b in combinations(arr, 2):
            if a + b in s:
                l = 3
                a, b = b, a + b
                while a + b in s:
                    l += 1
                    a, b = b, a + b
                ans = ans if ans >= l else l
        return ans
