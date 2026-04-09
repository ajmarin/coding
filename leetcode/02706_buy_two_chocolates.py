class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        low, second = 1000, 1000
        for p in prices:
            if p < low:
                low, second = p, low
            elif p < second:
                second = p
        needed = low + second
        return money if needed > money else money - needed
