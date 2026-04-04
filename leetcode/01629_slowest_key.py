class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        prev, key = 0, "a"
        longest = -1
        for i, release in enumerate(releaseTimes):
            duration = release - prev
            prev = release
            if duration > longest or (duration == longest and keysPressed[i] > key):
                key = keysPressed[i]
                longest = duration
        return key
