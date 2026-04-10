class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return "".join(next(zip(*words))) == s
