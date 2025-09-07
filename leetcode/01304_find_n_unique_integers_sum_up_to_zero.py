 class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [0] if n & 1 else []
        x = 1
        for _ in range(n // 2):
            ans.append(x)
            ans.append(-x)
            x += 1
        return ans

