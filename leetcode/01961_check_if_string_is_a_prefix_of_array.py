class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        concat, l = "", len(s)
        for w in words:
            concat += w
            if len(concat) >= l:
                break
        return concat == s
