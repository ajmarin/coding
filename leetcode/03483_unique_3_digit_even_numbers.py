class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        return len(
            set(
                100 * a + 10 * b + c
                for a, b, c in permutations(digits, 3)
                if a and not c & 1
            )
        )
