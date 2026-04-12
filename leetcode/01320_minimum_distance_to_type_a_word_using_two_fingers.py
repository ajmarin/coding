class Solution:
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        dp = [[0] * 26] + [[inf] * 26 for _ in range(n - 1)]

        def get_cost(u: int, v: int) -> int:
            return abs(u // 6 - v // 6) + abs(u % 6 - v % 6)

        prev, prev_char = dp[0], ord(word[0]) - ord("A")
        for i in range(1, n):
            curr, curr_char = dp[i], ord(word[i]) - ord("A")
            d = get_cost(curr_char, prev_char)
            for j in range(26):
                # Move finger that typed prev char
                curr[j] = min(curr[j], prev[j] + d)
                # Move other finger
                curr[prev_char] = min(curr[prev_char], prev[j] + get_cost(j, curr_char))
            prev, prev_char = curr, curr_char
        return min(dp[-1])
