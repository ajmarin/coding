balloon = Counter("balloon")


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = Counter(text)
        return min(cnt[c] // balloon[c] for c in "ablon")
