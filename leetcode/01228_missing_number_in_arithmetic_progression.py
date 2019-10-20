class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        r = (arr[len(arr) - 1] - arr[0]) // len(arr)
        expected = arr[0]
        for x in arr:
            if x != expected:
                break
            expected += r
        return expected