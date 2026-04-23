class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        indices = defaultdict(list)
        for i, n in enumerate(nums):
            indices[n].append(i)
        ans = [0] * len(nums)
        for num, idx in indices.items():
            left, right = 0, sum(idx)
            pos_mul = 1 - len(idx)
            for pos in idx:
                right -= pos
                ans[pos] = pos_mul * pos + right - left
                pos_mul += 2
                left += pos
        return ans
