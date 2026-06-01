class Solution:
    def minimumCost(
        self, s: str, t: str, flipCost: int, swapCost: int, crossCost: int
    ) -> int:
        one_zero = zero_one = 0
        for a, b in zip(s, t):
            if a == "0" and b == "1":
                zero_one += 1
            elif a == "1" and b == "0":
                one_zero += 1
        pairs = min(one_zero, zero_one)
        cost = pairs * min(swapCost, 2 * flipCost)
        rem = one_zero + zero_one - 2 * pairs
        if rem & 1:
            cost += flipCost
            rem -= 1
        cost += (rem >> 1) * min(crossCost + swapCost, 2 * flipCost)
        return cost
