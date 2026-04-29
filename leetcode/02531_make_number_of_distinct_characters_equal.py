class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        c1, c2 = Counter(word1), Counter(word2)
        if abs(len(c1) - len(c2)) > 2:
            return False
        cnz = lambda c: len([*filter(None, c.values())])

        def swap(char: str, direction: int):
            c1[char] += direction
            c2[char] -= direction

        to_send, to_receive = list(c1.keys()), list(c2.keys())
        for s in to_send:
            swap(s, -1)
            for r in to_receive:
                swap(r, 1)
                if cnz(c1) == cnz(c2):
                    return True
                swap(r, -1)
            swap(s, 1)
        return False
