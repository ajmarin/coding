class Solution:
    def countValidWords(self, sentence: str) -> int:
        def is_valid(word: str) -> bool:
            if not word or any(c.isdigit() for c in word):
                return False
            has_dash = False
            length = len(word)
            for i, c in enumerate(word):
                if c.isalpha():
                    continue
                if c == "-":
                    if has_dash:
                        return False
                    has_dash = True
                    if (
                        i == 0
                        or i == length - 1
                        or not word[i - 1].isalpha()
                        or not word[i + 1].isalpha()
                    ):
                        return False
                elif i != length - 1:
                    return False
            return True

        return sum(is_valid(w) for w in sentence.split(" "))
