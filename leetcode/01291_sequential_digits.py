class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []

        def bt(curr: int, d: int):
            if low <= curr <= high:
                ans.append(curr)
            if d > 9 or curr > high:
                return
            bt(10 * curr + d, d + 1)

        for d in range(9):
            bt(0, d + 1)
        ans.sort()

        return ans
