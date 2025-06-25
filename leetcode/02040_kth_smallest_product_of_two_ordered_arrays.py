class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        values = [nums1[i] * nums2[j] for i in (0, -1) for j in (0, -1)]
        low, high = min(values), max(values)
        n2 = len(nums2)

        first_zero = bisect_left(nums1, 0)
        after_last_zero = bisect_right(nums1, 0)
        base_score = n2 * (after_last_zero - first_zero)

        negatives = nums1[:first_zero]
        positives = nums1[after_last_zero:]

        while low <= high:
            prod = (low + high) >> 1
            total = base_score if prod >= 0 else 0
            for num in positives:
                total += bisect_right(nums2, prod // num)
            for num in negatives:
                total += n2 - bisect_left(nums2, -(-prod // num))
            if total < k:
                low = prod + 1
            else:
                high = prod - 1
        return low

