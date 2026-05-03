class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        reached = set()
        ans = []
        maxi, maxj = len(nums1) - 1, len(nums2) - 1
        min_sum = [(nums1[0] + nums2[0], 0, 0)]
        for _ in range(k):
            _, i, j = heappop(min_sum)
            ans.append([nums1[i], nums2[j]])
            if i != maxi and (i + 1, j) not in reached:
                reached.add((i + 1, j))
                heappush(min_sum, (nums1[i + 1] + nums2[j], i + 1, j))
            if j != maxj and (i, j + 1) not in reached:
                reached.add((i, j + 1))
                heappush(min_sum, (nums1[i] + nums2[j + 1], i, j + 1))
        return ans
