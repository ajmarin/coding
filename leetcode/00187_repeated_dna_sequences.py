class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        c = Counter(s[i : i + 10] for i in range(len(s) - 9))
        return [k for k, cnt in c.items() if cnt > 1]
