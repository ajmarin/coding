class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        for i in range(n - k, -1, -k):
            if word.endswith(word[:i]):
                return (n - i + k - 1) // k
        return (n + k - 1) // k
