INF = float("inf")
ORD0 = ord('0')

class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        INF = float("inf")
        ans = -inf
        mask = lambda a, b: ((a & 1) << 1) | (b & 1)
        s = [*map(lambda c: ord(c) - ORD0, s)]
        for a in range(5):
            for b in range(5):
                if a == b:
                    continue
                cnt_a, cnt_b, prev_a, prev_b = [0] * 4
                left = -1
                best = [INF] * 4
                for right, c in enumerate(s):
                    cnt_a += c == a
                    cnt_b += c == b
                    while right - left >= k and cnt_b - prev_b > 1:
                        ls = mask(prev_a, prev_b)
                        best[ls] = min(best[ls], prev_a - prev_b)
                        left += 1
                        prev_a += s[left] == a
                        prev_b += s[left] == b

                    wanted = mask(cnt_a, cnt_b) ^ 2
                    if best[wanted] != INF:
                        ans = max(ans, cnt_a - cnt_b - best[wanted])
        return ans

