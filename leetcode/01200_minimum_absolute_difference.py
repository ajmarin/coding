class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = min(arr[i + 1] - x for i, x in enumerate(arr[:-1]))
        return [[n, arr[i + 1]] for i, n in enumerate(arr[:-1]) if arr[i + 1] - n == min_diff]