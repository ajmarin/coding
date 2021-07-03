class Solution:
    def numSteps(self, s: str) -> int:
        s = list(map(int, s))
        ans, i = 0, len(s) - 1
        while i > 0:
            if s[i] == 0:
                ans += 1
                i -= 1
                continue
            for j in range(i - 1, -1, -1):
                if s[j] == 0:
                    break
            else:
                return ans + i + 2
            ans += i - j + 1
            i = j
            s[i] = 1
        return ans
