import heapq
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        N = len(nums)
        root = int(math.ceil(N ** .5))
        min_rmq = []
        max_rmq = []
        def get(arr, left: int, right: int, ans, func) -> int:
            for i in range(left // root, len(arr)):
                start = i * root
                if start > right:
                    break
                end = min(start + root, N)
                if left <= start and end <= right:
                    ans = func(ans, arr[i])
                else:
                    for j in range(max(left, start), min(end, right + 1)):
                        ans = func(ans, nums[j])
            return ans
        for i in range(0, N, root):
            low = float("inf")
            high = float("-inf")
            for j in range(i, min(i + root, N)):
                low = min(low, nums[j])
                high = max(high, nums[j])
            min_rmq.append(low)
            max_rmq.append(high)
        ans = 1
        left = 0
        right = 0
        get_max = lambda l, r: get(max_rmq, l, r, float("-inf"), max)
        get_min = lambda l, r: get(min_rmq, l, r, float("inf"), min)
        while right < N:
            while left < right and get_max(left, right) - get_min(left, right) > limit:
                left += 1
            high = get_max(left, right)
            low = get_min(left, right)
            while right < N and low <= nums[right] <= high:
                right += 1
            ans = max(ans, right - left)
        return ans