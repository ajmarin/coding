class Solution:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        i1 = i2 = 0
        n1, n2 = len(nums1), len(nums2)
        ans = []
        while i1 < n1 and i2 < n2:
            id1, val1 = nums1[i1]
            id2, val2 = nums2[i2]
            if id1 == id2:
                ans.append([id1, val1 + val2])
                i1 += 1
                i2 += 1
            elif id1 < id2:
                ans.append(nums1[i1])
                i1 += 1
            else:
                ans.append(nums2[i2])
                i2 += 1
        return ans + nums1[i1:] + nums2[i2:]
