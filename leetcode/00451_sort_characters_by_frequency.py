class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join(c * cnt for c, cnt in Counter(s).most_common())
