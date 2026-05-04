class Solution:
    def bestClosingTime(self, customers: str) -> int:
        ans, penalty = 0, customers.count("Y")
        lowest = penalty
        for i, c in enumerate(customers, 1):
            penalty += 1 if c == "N" else -1
            if penalty < lowest:
                ans = i
                lowest = penalty
        return ans
