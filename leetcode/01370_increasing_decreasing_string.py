class Solution:
    def sortString(self, s: str) -> str:
        cnt = Counter(s)
        chars = [c for c in string.ascii_lowercase if c in cnt]
        ans = []

        def add_to_ans(chars):
            for c in chars:
                if cnt[c] > 0:
                    ans.append(c)
                    cnt[c] -= 1

        while len(ans) < len(s):
            add_to_ans(chars)
            add_to_ans(reversed(chars))
        return "".join(ans)
