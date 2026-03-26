class Solution:
    def countSegments(self, s: str) -> int:
        return len([w for w in s.split(" ") if w])
