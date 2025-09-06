 class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        ans = 0
        for l, r in queries:
            p4 = divs = 1
            total = 0
            while p4 <= r:
                low = p4 if p4 > l else l
                end = 4 * p4 - 1
                high = end if end < r else r
                if high >= low:
                    total += divs * (high - low + 1)
                divs += 1
                p4 *= 4
            ans += (total + 1) >> 1
        return ans

