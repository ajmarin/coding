class Trie:
    def __init__(self):
        self.children = {}
        self.word_end = False

    def insert(self, word: str) -> None:
        if not word:
            self.word_end = True
            return
        first = word[0]
        if first not in self.children:
            self.children[first] = Trie()
        self.children[first].insert(word[1:])

    def search(self, word: str) -> bool:
        t = self
        for c in word:
            t = t.children.get(c, None)
            if t is None:
                break
        return t is not None and t.word_end

    def startsWith(self, prefix: str) -> bool:
        t = self
        for c in prefix:
            t = t.children.get(c, None)
            if t is None:
                return False
        return True