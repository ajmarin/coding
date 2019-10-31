class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        answer = set()
        for N in range(1, len(tiles) + 1):
            for j in itertools.permutations(tiles, N):
                answer.add(j)
        return len(answer)