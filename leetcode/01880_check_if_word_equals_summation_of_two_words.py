ORDA = ord("a")


def get_value(word: str):
    res = 0
    for c in word:
        res = res * 10 + ord(c) - ORDA
    return res


class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        return get_value(firstWord) + get_value(secondWord) == get_value(targetWord)
