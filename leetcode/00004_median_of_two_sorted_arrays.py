class Solution:
    def lower_bound(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

    def median(self, nums: List[int]) -> float:
        n = len(nums)
        halfn = n >> 1
        if n & 1:
            return nums[halfn]
        return (nums[halfn] + nums[halfn - 1]) / 2

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        INF = float("inf")
        if not nums1:
            return self.median(nums2)
        if not nums2:
            return self.median(nums1)

        left, right = 0, len(nums1)
        while left < right:
            mid = (left + right) >> 1
            index = self.lower_bound(nums2, nums1[mid])
            on_left = mid + index
            on_right = len(nums1) + len(nums2) - on_left - 1
            if on_left == on_right:
                return nums1[mid]
            if abs(on_left - on_right) == 1:
                if on_left > on_right:
                    a1 = nums2[index - 1] if index else -INF
                    a2 = nums1[mid - 1] if mid else -INF
                    return (nums1[mid] + max(a1, a2)) / 2
                else:
                    a1 = nums2[index] if index < len(nums2) else INF
                    a2 = nums1[mid + 1] if mid + 1 < len(nums1) else INF
                    return (nums1[mid] + min(a1, a2)) / 2
            if on_left < on_right:
                left = mid + 1
            else:
                right = mid
        return self.findMedianSortedArrays(nums2, nums1)