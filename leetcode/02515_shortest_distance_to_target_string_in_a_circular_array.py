class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        for i in range(1 + n // 2):
            right = (startIndex + i) % n
            left = (startIndex - i) % n
            if words[right] == target or words[left] == target:
                return i
        return -1
