class Solution:
    def clumsy(self, N: int) -> int:
        def helper(N: int):
            if N >= 3:
                return N * (N - 1) // (N - 2)
            if N == 2:
                return N * (N - 1)
            return N
        answer = helper(N)
        N -= 3
        while N > 0:
            answer += N
            answer -= helper(N - 1)
            N -= 4
        return answer