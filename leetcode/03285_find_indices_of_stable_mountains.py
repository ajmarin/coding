class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i + 1 for i in range(len(height) - 1) if height[i] > threshold]
