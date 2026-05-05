MOD = 10**9 + 7


class Solution:
    def alternatingXOR(self, nums: List[int], target1: int, target2: int) -> int:
        states = [0, target1, target1 ^ target2, target2]
        prev, dp = [1, 0, 0, 0], [1, 0, 0, 0]
        xor = 0
        for n in nums[:-1]:
            xor ^= n
            for i in range(4):
                if xor == states[i]:
                    dp[i] = (dp[i] + prev[(i + 3) % 4]) % MOD
            prev[:] = dp
        xor ^= nums[-1]
        return sum(dp[(j + 3) % 4] for j in range(4) if xor == states[j]) % MOD
