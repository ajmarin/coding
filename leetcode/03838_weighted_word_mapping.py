class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        get_weight = lambda word: sum(weights[ord(c) - ord("a")] for c in word)
        return "".join(chr(ord("z") - get_weight(w) % 26) for w in words)
