cleanup = str.maketrans(
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?',;.", "abcdefghijklmnopqrstuvwxyz      "
)


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banned = set(banned)
        c = Counter()
        for word in paragraph.translate(cleanup).split(" "):
            if not word:
                continue
            c[word] += 1
        highest = 0
        ans = ""
        for word, count in c.items():
            if word not in banned and count > highest:
                highest = count
                ans = word
        return ans
