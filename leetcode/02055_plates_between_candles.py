class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        plates = [0] * n
        left_candle, right_candle = [-1] * n, [-1] * n
        count = 0
        left = right = -1
        for i, c in enumerate(s):
            if c == '*': count += 1
            else: left = i
            plates[i] = count
            left_candle[i] = left
            ri = n + ~i
            if s[ri] == '|': right = ri
            right_candle[ri] = right

        ans = []
        for l, r in queries:
            left = right_candle[l]
            right = left_candle[r]
            if left == -1 or right == -1 or left >= right:
                ans.append(0)
            else:
                ans.append(plates[right] - plates[left])
        return ans

