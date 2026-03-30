class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        positions = [index for index in range(len(s)) if s[index] == c]
        ans = [0] * len(s)
        ans[: positions[0]] = range(positions[0], 0, -1)
        for left, right in zip(positions, positions[1:]):
            value = 0
            while left <= right:
                ans[left] = ans[right] = value
                left += 1
                right -= 1
                value += 1
        ans[positions[-1] :] = range(len(s) - positions[-1])
        return ans
