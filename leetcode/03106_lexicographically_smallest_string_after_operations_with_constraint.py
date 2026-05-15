class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        ORDA = ord("a")
        chars = list(s)
        for i, c in enumerate(chars):
            index = ord(c) - ORDA
            dist_to_a = min(index, 26 - index)
            if dist_to_a > k:
                chars[i] = chr(index - k + ORDA)
                break
            chars[i] = "a"
            k -= dist_to_a
        return "".join(chars)
