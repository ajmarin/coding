class Solution:
    def compressedString(self, word: str) -> str:
        ans = ""
        last = "_"
        count = 0
        for c in word + "_":
            if c != last:
                for _ in range(count // 9):
                    ans += f"9{last}"
                if count % 9:
                    ans += f"{count % 9}{last}"
                count = 0
            last = c
            count += 1
        return ans
