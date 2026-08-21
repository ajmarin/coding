class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins.sort()
        filtered = []
        for c in coins:
            if all(c % fc for fc in filtered):
                filtered.append(c)
        coins = filtered
        n = len(coins)

        add, sub = [], []
        for count in range(1, n + 1):
            l = add if count & 1 else sub
            for comb in combinations(coins, count):
                l.append(lcm(*comb))

        def impossible(x: int) -> int:
            return sum(x // a for a in add) - sum(x // s for s in sub) < k

        low, high = k, coins[-1] * k + 1
        while low < high:
            m = (low + high) >> 1
            if impossible(m):
                low = m + 1
            else:
                high = m
        return low
