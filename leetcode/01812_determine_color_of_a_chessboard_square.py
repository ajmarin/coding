class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        row, col = int(coordinates[1]), ord(coordinates[0]) - ord("a")
        return (row + col) % 2 == 0
