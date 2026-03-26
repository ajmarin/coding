class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        seen = set()
        words = s.split(" ")
        mapping = {}
        if len(pattern) != len(words):
            return False
        for pos, c in enumerate(pattern):
            if c in mapping:
                if words[pos] != mapping[c]:
                    return False
            else:
                mapping[c] = w = words[pos]
                if w in seen:
                    return False
                seen.add(w)
        return True
