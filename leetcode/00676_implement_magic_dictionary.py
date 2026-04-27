class MagicDictionary:
    def __init__(self):
        self.words_by_len = defaultdict(list)

    def buildDict(self, dictionary: List[str]) -> None:
        words = self.words_by_len
        for word in dictionary:
            words[len(word)].append(word)

    def isOneEditAway(self, word: str, searchWord: str) -> bool:
        count = 0
        for a, b in zip(word, searchWord):
            if a != b and (count := count + 1) == 2:
                break
        return count == 1

    def search(self, searchWord: str) -> bool:
        return any(
            self.isOneEditAway(word, searchWord)
            for word in self.words_by_len[len(searchWord)]
        )
