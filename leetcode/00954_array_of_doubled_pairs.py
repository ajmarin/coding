class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        A = list(map(abs,A))
        A.sort()
        count = collections.Counter(A)
        for n in A:
            if not count[n]:
                continue
            count[n] -= 1
            if count[n << 1]:
                count[n << 1] -= 1
                continue
            return False
        return True