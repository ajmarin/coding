class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        parts = s.split()
        return len(parts[-1]) if parts else 0