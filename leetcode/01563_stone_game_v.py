class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        acc = [0] + list(accumulate(stoneValue))

        @cache
        def dp(l: int, r: int) -> int:
            if l >= r:
                return 0
            right = acc[r + 1] - acc[l]
            ans = left = 0
            for m in range(l, r):
                left += stoneValue[m]
                right -= stoneValue[m]
                if left < right:
                    if ans < 2 * left:
                        cand = left + dp(l, m)
                        ans = ans if ans >= cand else cand
                elif left > right:
                    if ans >= 2 * right:
                        break
                    cand = right + dp(m + 1, r)
                    ans = ans if ans >= cand else cand
                else:
                    ans = max(ans, left + dp(l, m), right + dp(m + 1, r))
            return ans

        return dp(0, len(stoneValue) - 1)
