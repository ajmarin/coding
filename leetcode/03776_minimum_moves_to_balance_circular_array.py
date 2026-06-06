class Solution:
    def minMoves(self, balance: List[int]) -> int:
        if sum(balance) < 0:
            return -1

        n = len(balance)
        negative = next((i for i in range(n) if balance[i] < 0), -1)
        if negative == -1:
            return 0

        bal = -balance[negative]

        def borrow(pos: int) -> int:
            nonlocal bal
            borrowed = balance[pos] if balance[pos] < bal else bal
            bal -= borrowed
            return borrowed

        cost = 0
        for dist in range(1, n):
            left = (negative - dist) % n
            cost += borrow(left) * dist
            if not bal:
                return cost
            right = (negative + dist) % n
            cost += borrow(right) * dist
            if not bal:
                return cost
