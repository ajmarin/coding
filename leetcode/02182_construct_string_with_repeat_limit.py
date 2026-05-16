class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = Counter(s)
        rev = sorted(cnt.keys(), reverse=True)
        sepi = 0
        ans = ""
        for i, c in enumerate(rev):
            while True:
                ans += c * min(cnt[c], repeatLimit)
                if cnt[c] <= repeatLimit:
                    del cnt[c]
                    break
                cnt[c] -= repeatLimit
                sepi = next(
                    (j for j in range(max(i + 1, sepi), len(rev)) if cnt[rev[j]]), -1
                )
                if sepi == -1:
                    break
                ans += rev[sepi]
                cnt[rev[sepi]] -= 1
        return ans
