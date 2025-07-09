class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        ans, index = float("inf"), {}
        for pos, n in enumerate(cards):
            last = index.get(n)
            if last is not None:
                cand = pos - last
                ans = cand if cand < ans else ans
            index[n] = pos
        return ans + 1 if ans != float("inf") else -1

