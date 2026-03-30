class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives = tens = 0
        for b in bills:
            if b == 5:
                fives += 1
            elif b == 10:
                if not fives:
                    return False
                fives -= 1
                tens += 1
            elif b == 20:
                if fives < 1:
                    return False
                if tens:
                    tens -= 1
                    fives -= 1
                elif fives > 2:
                    fives -= 3
                else:
                    return False
        return True
