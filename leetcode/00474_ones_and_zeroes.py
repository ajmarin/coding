class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = {(0, 0): 0}
        for s in strs:
            zeroes = s.count("0")
            ones = len(s) - zeroes
            update = {}
            for (z, o), cnt in dp.items():
                nz, no = zeroes + z, ones + o
                if nz > m or no > n:
                    continue
                k = nz, no
                if cnt + 1 > dp.get(k, 0):
                    update[k] = cnt + 1
            dp.update(update)
        return max(dp.values())
