class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.end = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.children[c]
        node.end = True

    def searchTree(self, word: str, node: TrieNode, index=0) -> bool:
        if index == len(word):
            return node.end
        c = word[index]
        index += 1
        if c == ".":
            return any(
                self.searchTree(word, child, index) for child in node.children.values()
            )
        return c in node.children and self.searchTree(word, node.children[c], index)

    def search(self, word: str) -> bool:
        return self.searchTree(word, self.root)
