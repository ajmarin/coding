def invert(s: str):
    return s.replace("0", "-").replace("1", "0").replace("-", "1")


s = ["", "0"]
for i in range(2, 21):
    prev = s[i - 1]
    s.append(prev + "1" + invert(prev)[::-1])


class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        return s[n][k - 1]
