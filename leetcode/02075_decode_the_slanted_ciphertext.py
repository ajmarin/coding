class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        l = len(encodedText)
        cols = l // rows
        step = cols + 1
        ans = []
        for col in range(cols):
            for pos in range(col, l, step):
                ans.append(encodedText[pos])
        return "".join(ans).rstrip()
