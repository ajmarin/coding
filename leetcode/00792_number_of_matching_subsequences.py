class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        iters = defaultdict(list)
        for w in words:
            it = iter(w)
            iters[next(it)].append(it)
        for c in s:
            moving_ahead = iters[c]
            iters[c] = []
            for it in moving_ahead: iters[next(it, "@")].append(it)
        return len(iters["@"])

