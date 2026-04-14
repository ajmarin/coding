class Solution:
    def canAliceWin(self, n: int) -> bool:
        alice_wins = False
        remove = 10
        while n >= remove:
            n -= remove
            remove -= 1
            alice_wins = not alice_wins
        return alice_wins
