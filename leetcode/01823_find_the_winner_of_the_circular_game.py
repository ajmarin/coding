class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        players = list(range(n))
        k -= 1
        at = 0
        for n in range(n, 1, -1):
            at = (at + k) % n
            players.remove(players[at])
        return 1 + players[0]
