class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        left, right = 1, len(arr)
        while left < right:
            mid = (left + right) >> 1
            if arr[mid - 1] < arr[mid]:
                left = mid + 1
            else:
                right = mid
        return left - 1
