class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return len(moves) - 2 * min(moves.count("L"), moves.count("R"))
