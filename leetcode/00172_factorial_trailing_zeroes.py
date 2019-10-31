class Solution:
    def trailingZeroes(self, n: int) -> int:
        answer, div = 0, 5
        while div <= n:
            answer += n // div
            div *= 5
        return answer