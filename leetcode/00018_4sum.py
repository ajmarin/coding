class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        sums_of_two = collections.defaultdict(list)
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                sums_of_two[nums[i] + nums[j]].append((i, j))
        
        res = set()
        for total, indices in sums_of_two.items():
            remaining = target - total
            if remaining < total or remaining not in sums_of_two:
                continue
            for a, b in indices:
                for c, d in sums_of_two[remaining]:
                    if c <= b:
                        continue
                    res.add(tuple(nums[x] for x in [a, b, c, d]))
        return res