class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        rows = defaultdict(list)
        counts = [0] * (1 + len(nums))
        for n in nums:
            rows[counts[n]].append(n)
            counts[n] += 1
        return list(rows.values())
