class Solution:
    def numsSameConsecDiff(self, N, K):
        answer = []
        def bt(n: int, d: int) -> int:
            if d == 0:
                answer.append(n)
                return
            last = n % 10
            n *= 10
            if last >= K:
                bt(n + last - K, d - 1)
            if K and last + K < 10:
                bt(n + last + K, d - 1)
        for i in range(N > 1, 10):
            bt(i, N - 1)
        return answer