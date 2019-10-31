class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        ans, left, right, N = 0, None, 0, len(seats)
        for i in range(N):
            if seats[i]:
                left = i
                continue
            right = max(right, i + 1)
            while right < N and not seats[right]:
                right += 1
            d1 = N if left is None else i - left
            d2 = N if right == N else right - i
            ans = max(ans, min(d1, d2))
        return ans