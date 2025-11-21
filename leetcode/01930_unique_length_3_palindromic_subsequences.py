class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        indices = defaultdict(list)
        for i, c in enumerate(s):
            indices[c].append(i)
        ans = 0
        for k in indices:
            curr = indices[k]
            first, last = curr[0], curr[-1]
            if first == last:
                continue
            for c in indices:
                indc = indices[c]
                x = bisect_right(indc, first)
                ans += x < len(indc) and indc[x] < last
        return ans
