class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        components = []
        mult = 1
        while n:
            d = n % 10
            if d:
                components.append(d * mult)
            mult *= 10
            n //= 10
        return components[::-1]
