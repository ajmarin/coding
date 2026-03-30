class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        index = dict((c, i) for i, c in enumerate(order))

        def is_lte(a: str, b: str) -> bool:
            for ca, cb in zip(a, b):
                diff = index[ca] - index[cb]
                if diff == 0:
                    continue
                return diff < 0
            return len(a) <= len(b)

        return all(is_lte(w1, w2) for w1, w2 in zip(words, words[1:]))
