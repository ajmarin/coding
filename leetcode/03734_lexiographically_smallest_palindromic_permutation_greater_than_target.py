class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = {c: 0 for c in ascii_lowercase}
        for c in s:
            cnt[c] += 1
        it = iter(cnt.items())
        odd = next((k for k, c in it if c & 1), "")
        if next((k for k, c in it if c & 1), None) is not None:
            return ""
        for k in cnt:
            cnt[k] //= 2

        goal = n // 2

        def bt(index: int, curr: str) -> str:
            if index == goal:
                if odd > target[index] or (
                    (odd == "" or odd == target[index])
                    and curr[::-1] > target[index + (odd != "") :]
                ):
                    return curr + odd + curr[::-1]
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
                return ans + odd + ans[::-1]
            return ""

        return bt(0, "")
