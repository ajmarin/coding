class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        maxz = math.floor(len(s) ** 0.5) + 1
        last_zero = -1
        prev_zero = []
        for i, c in enumerate(s):
            prev_zero.append(last_zero)
            if c == "0":
                last_zero = i

        ans = 0
        for i, c in enumerate(s):
            zeroes = c == "0"
            ones = 1 - zeroes
            while i >= 0:
                gap_size = i - prev_zero[i]
                ones += gap_size - 1
                delta = 1 + ones - zeroes * zeroes
                if delta > 0:
                    ans += delta if delta < gap_size else gap_size
                i = prev_zero[i]
                if (zeroes := zeroes + 1) == maxz:
                    break
        return ans
