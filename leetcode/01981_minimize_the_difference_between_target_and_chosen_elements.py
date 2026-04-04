class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        prev = {0}
        lower_bound = sum(map(min, mat))
        if lower_bound >= target:
            return lower_bound - target
        upper_bound = 2 * target - lower_bound
        for row in mat:
            possible = set()
            for n in row:
                for x in prev:
                    if n + x < upper_bound:
                        possible.add(n + x)
            prev = possible
        return min(abs(x - target) for x in prev)
