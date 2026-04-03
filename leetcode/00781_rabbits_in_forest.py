class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum((v + n) // (n + 1) * (n + 1) for n, v in Counter(answers).items())
