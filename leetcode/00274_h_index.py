class Solution:
    def hIndex(self, citations: List[int]) -> int:
        c = Counter(citations)
        remaining = len(citations)
        h_poss = sorted(c.keys())
        pos = 0
        for i in range(len(citations) + 2):
            if i > remaining:
                break
            if i == h_poss[pos]:
                pos += 1
                remaining -= c[i]
        return i - 1
