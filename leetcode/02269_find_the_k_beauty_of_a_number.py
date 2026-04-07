class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        ans = 0
        for i in range(len(s) - k + 1):
            subs = int(s[i : i + k])
            ans += subs and num % subs == 0
        return ans
