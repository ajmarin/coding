class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        return [
            a for a, b in product(map(min, matrix), map(max, zip(*matrix))) if a == b
        ]
