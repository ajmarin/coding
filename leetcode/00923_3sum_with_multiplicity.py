class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        c, w = collections.Counter(A), 0
        for i, j in itertools.combinations_with_replacement(c, 2):
            k = target - i - j
            wi = c[i]
            if i == j == k: w += (wi) * (wi - 1) * (wi - 2) // 6
            elif i == j: w += (wi) * (wi - 1) // 2 * c[k]
            elif i < k and j < k: w += wi * c[j] * c[k]
        return w % (10**9 + 7)