class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        t = collections.Counter()
        for a, b in trust:
            t[b] += 1
            t[a] -= 1
        for i in range(1, N + 1):
            if t[i] == N - 1:
                return i
        return -1