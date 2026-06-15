class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = {c: 0 for c in ascii_lowercase}
        for c in s:
            cnt[c] += 1

        def bt(index: int, curr: str) -> str:
            if index == n:
                return ""
            x = target[index]
            if cnt[x]:
                cnt[x] -= 1
                cand = bt(index + 1, curr + x)
                if cand:
                    return cand
                cnt[x] += 1
            for c in ascii_lowercase[ascii_lowercase.index(x) + 1 :]:
                if not cnt[c]:
                    continue
                ans = curr + c
                cnt[c] -= 1
                for c in ascii_lowercase:
                    ans += c * cnt[c]
                return ans
            return ""

        return bt(0, "")
