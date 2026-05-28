class Trie:
    def __init__(self, index):
        self.children = {}
        self.index = index


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        n = len(wordsContainer)
        root = Trie(min(range(n), key=lambda i: len(wordsContainer[i])))

        for i, word in enumerate(wordsContainer):
            at = root
            l = len(word)
            for c in word[::-1]:
                if c not in at.children:
                    at.children[c] = Trie(i)
                at = at.children[c]
                if l < len(wordsContainer[at.index]):
                    at.index = i

        ans = []
        for w in wordsQuery:
            at = root
            for c in w[::-1]:
                if c not in at.children:
                    break
                at = at.children[c]
            ans.append(at.index)
        return ans
