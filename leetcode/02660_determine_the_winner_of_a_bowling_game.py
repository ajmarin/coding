def get_score(plays: List[int]) -> int:
    a = b = score = 0
    for p in plays:
        score += p << (a == 10 or b == 10)
        a, b = b, p
    return score


class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        s1, s2 = get_score(player1), get_score(player2)
        return 0 if s1 == s2 else 1 + (s2 > s1)
