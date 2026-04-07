class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = k
        blacks = 0
        for i, c in enumerate(blocks):
            blacks += c == "B"
            if i >= k:
                blacks -= blocks[i - k] == "B"
            ans = min(ans, k - blacks)
        return ans
