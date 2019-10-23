class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        cnt = collections.Counter(secret)
        bulls, cows = 0, 0
        for i, c in enumerate(secret):
            if guess[i] == c:
                bulls += 1
                cnt[c] -= 1
        for i, c in enumerate(guess):
            if secret[i] != c and cnt[c]:
                cnt[c] -= 1
                cows += 1
        return f'{bulls}A{cows}B'