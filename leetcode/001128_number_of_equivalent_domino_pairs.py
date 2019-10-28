class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dominoes = (10 * a + b if a < b else 10 * b + a for a, b in dominoes)
        return sum(x * (x - 1) >> 1 for x in collections.Counter(dominoes).values())