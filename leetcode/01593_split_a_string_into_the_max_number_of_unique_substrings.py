class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        n = len(s)
        seen = set()

        def bt(index: int, curr=""):
            if index == n:
                return 0 if curr in seen else 1 + len(seen)

            ans = bt(index + 1, curr + s[index])
            if curr and curr not in seen:
                seen.add(curr)
                cand = bt(index + 1, s[index])
                ans = cand if cand > ans else ans
                seen.remove(curr)
            return ans

        return bt(0)
