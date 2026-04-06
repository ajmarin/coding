def capitalize(word: str) -> str:
    return word.lower() if len(word) < 3 else word[0].upper() + word[1:].lower()


class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return " ".join(capitalize(w) for w in title.split(" "))
