class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        money -= children
        eights = min(money // 7, children)
        rem = money - 7 * eights
        return eights - (
            (rem and children == eights) or (children - eights == 1 and rem == 3)
        )
