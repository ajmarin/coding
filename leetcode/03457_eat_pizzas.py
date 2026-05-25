class Solution:
    def maxWeight(self, pizzas: List[int]) -> int:
        n = len(pizzas)
        pizzas.sort()
        days = n >> 2
        odd = (days + 1) >> 1
        even = days - odd
        return sum(pizzas[-odd:]) + sum(pizzas[-odd - 2 : -odd - 2 * (even + 1) : -2])
