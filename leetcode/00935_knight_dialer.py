class Solution:
    def knightDialer(self, N: int) -> int:
        ways = [[x]*10 for x in (1,0)]
        prev = [[4,6],[6,8],[7,9],[4,8],[0,3,9],[],[0,1,7],[2,6],[1,3],[2,4]]
        MOD = 10**9 + 7
        N += 1
        for i in range(1, N):
            c = ways[i & 1]
            p = ways[(i & 1) ^ 1]
            for i in range(10):
                c[i] = sum(p[x] for x in prev[i]) % MOD
        return sum(ways[N & 1]) % MOD