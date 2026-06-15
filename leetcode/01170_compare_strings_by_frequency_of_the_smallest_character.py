def f(s: str) -> int:
    return s.count(min(s))


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        counts = [0] * 12
        for w in words:
            counts[f(w)] += 1
        for i in range(10, -1, -1):
            counts[i] += counts[i + 1]
        return [counts[f(q) + 1] for q in queries]
