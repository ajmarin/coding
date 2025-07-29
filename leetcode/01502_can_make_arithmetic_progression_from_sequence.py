class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1] - arr[0]
        return all(b - a == diff for a, b in zip(arr, arr[1:]))

