def score(seq: List[int]):
    if not seq: return 0
    N = len(seq)
    seq.sort()
    seq.append(-1)
    longest = curr = 1
    prev = seq[0]
    for x in seq[1:]:
        curr += 1
        if x != prev + 1:
            longest = curr if curr > longest else longest
            curr = 1
        prev = x
    return longest

class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        return min(score(hBars), score(vBars)) ** 2

