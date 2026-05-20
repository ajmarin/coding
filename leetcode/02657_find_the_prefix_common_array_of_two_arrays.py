class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        c = [0] * (len(A) + 1)
        prefix_common = 0
        ans = []
        for a, b in zip(A, B):
            c[a] += 1
            c[b] += 1
            prefix_common += (c[a] == 2) + (a != b and c[b] == 2)
            ans.append(prefix_common)
        return ans
