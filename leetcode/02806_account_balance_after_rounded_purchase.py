class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        last_digit = purchaseAmount % 10
        return (
            100 - purchaseAmount + (last_digit if last_digit < 5 else last_digit - 10)
        )
