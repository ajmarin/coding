class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        seen = set([0])
        for n1 in arr1:
            while n1:
                seen.add(n1)
                n1 //= 10

        ans = 0
        for n2 in arr2:
            while n2 not in seen:
                n2 //= 10
            if n2:
                cand = len(str(n2))
                ans = cand if cand > ans else ans
        return ans

