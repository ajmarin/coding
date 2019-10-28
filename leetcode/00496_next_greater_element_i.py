class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        for n in nums1:
            index = nums2.index(n)
            for j in range(index, len(nums2)):
                if nums2[j] > n:
                    ans.append(nums2[j])
                    break
            else:
                ans.append(-1)
        return ans