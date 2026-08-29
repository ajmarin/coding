class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        prev = nums[0]
        groups = [deque([])]
        gidx = {}
        idx = 0
        for n in sorted(nums):
            if n - prev > limit:
                groups.append(deque([]))
                idx += 1
            groups[-1].append(n)
            gidx[n] = idx
            prev = n
        return [groups[gidx[n]].popleft() for n in nums]
