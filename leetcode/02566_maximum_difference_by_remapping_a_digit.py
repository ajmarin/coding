def replace(digits: List[int], replace: int, by: int) -> int:
    result = 0
    for d in digits:
        result = 10 * result + (by if d == replace else d)
    return result

class Solution:
    def minMaxDifference(self, num: int) -> int:
        d = []
        while num:
            d.append(num % 10)
            num //= 10
        d = d[::-1]
        to_replace = next((x for x in d if x != 9), None)
        return replace(d, to_replace, 9) - replace(d, d[0], 0)

