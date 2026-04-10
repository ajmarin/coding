class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        return list(chain(*(filter(None, w.split(separator)) for w in words)))
