class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        left = 0
        for i in range(k, len(energy)):
            prev = energy[left]
            if prev > 0:
                energy[i] += prev
            left += 1
        return max(energy[-k:])
