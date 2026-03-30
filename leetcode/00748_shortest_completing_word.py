class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        plate = Counter(
            [c for c in licensePlate.lower() if c in string.ascii_lowercase]
        )
        ans, best = "", 100
        for w in words:
            if len(w) >= best:
                continue
            word_count = Counter(w)
            if all(plate[c] <= word_count[c] for c in plate):
                ans = w
                best = len(w)
        return ans
