class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        button, longest = events[0]
        prev = longest
        for b, at in events:
            duration = at - prev
            if duration > longest:
                button, longest = b, duration
            elif duration == longest:
                button = b if b < button else button
            prev = at
        return button
