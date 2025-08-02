class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        c1 = Counter(basket1)
        c2 = Counter(basket2)
        total = Counter(c1)
        total.update(c2)
        if any(v & 1 for v in total.values()): return -1

        def to_swap(cnt):
            r = []
            for num, v in cnt.items():
                r += [num] * (v - (total[num] >> 1))
            return r

        swap1 = sorted(to_swap(c1))
        swap2 = sorted(to_swap(c2), reverse=True)

        swap_cost = 2 * min(total)
        return sum(min(a, b, swap_cost) for a, b in zip(swap1, swap2))

