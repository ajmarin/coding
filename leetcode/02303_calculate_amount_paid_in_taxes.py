class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        prev_upper = total = 0
        for upper, percent in brackets:
            amount = min(income, upper) - prev_upper
            total += amount * percent / 100
            prev_upper = upper
            if income <= upper:
                break
        return total
