class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        valid = [True] * (n + 1)
        for b in banned:
            if b <= n:
                valid[b] = False
        ans = total = 0
        for i in range(1, n + 1):
            if valid[i]:
                if total + i <= maxSum:
                    total += i
                    ans += 1
                else:
                    break
        return ans
