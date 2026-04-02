class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        matches = 0
        target = (k - 1) * m
        for i in range(len(arr) - m):
            if arr[i] == arr[i + m]:
                matches += 1
                if matches == target:
                    return True
            else:
                matches = 0
        return False
