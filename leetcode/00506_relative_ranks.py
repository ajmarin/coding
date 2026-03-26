MEDALS = ["Gold", "Silver", "Bronze"]


def map_rank(r):
    if r < 3:
        return f"{MEDALS[r]} Medal"
    return str(r + 1)


class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        ranks = sorted(range(n), key=lambda i: score[i], reverse=True)
        ans = [""] * n
        for i, r in enumerate(ranks):
            ans[r] = map_rank(i)
        return ans
