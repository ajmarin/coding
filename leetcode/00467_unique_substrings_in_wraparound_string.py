ORDA = ord("a")


class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        successor = {"_": "_"}
        prev = "z"
        for c in ascii_lowercase:
            successor[prev] = c
            prev = c
        longest = defaultdict(int)
        length, prev = 0, "_"
        for i, c in enumerate(s + prev):
            if c == successor[prev]:
                length += 1
            else:
                for x, size in zip(s[i - length : i], range(length, 0, -1)):
                    longest[x] = max(longest[x], size)
                length = 1
            prev = c
        return sum(longest.values())
