class Solution:
    def equalFrequency(self, word: str) -> bool:
        freq_counts = Counter(Counter(word).values())
        highest = max(freq_counts)
        n = sum(freq_counts.values())
        return (
            n == 1
            or highest == 1
            or (freq_counts[1] == 1 and freq_counts[highest] == n - 1)
            or (
                len(freq_counts) == 2
                and freq_counts[highest] == 1
                and highest - 1 in freq_counts
            )
        )
