class Solution:
    def minLength(self, s: str, numOps: int) -> int:
        nums = list(map(int, s))
        sizes = [len(list(g)) for _, g in groupby(nums)]

        def requiredOps(length):
            if length != 1:
                lp1 = length + 1
                return sum(s // lp1 for s in sizes)
            odd = sum(n == i & 1 for i, n in enumerate(nums))
            even = sum(n != i & 1 for i, n in enumerate(nums))
            return min(odd, even)

        low, high = 1, len(s)
        while low <= high:
            mid = (low + high) >> 1
            if requiredOps(mid) > numOps:
                low = mid + 1
            else:
                high = mid - 1
        return low

