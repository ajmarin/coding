COPRIME = [[gcd(i, j) == 1 for j in range(10)] for i in range(10)]


class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        c, n = Counter(), len(nums)

        ans = 0
        for i in range(n):
            ni = nums[i]
            last_i = ni % 10
            ans += sum(c[d] for d in range(1, 10) if COPRIME[d][last_i])
            c[ni // 10 ** floor(log10(ni))] += 1

        return ans
