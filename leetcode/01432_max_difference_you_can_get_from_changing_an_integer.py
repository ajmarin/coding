def replace(digits: List[int], replace: int, by: int) -> int:
    result = 0
    for d in digits:
        result = 10 * result + (by if d == replace else d)
    return result

class Solution:
    def maxDiff(self, num: int) -> int:
        d = []
        while num:
            d.append(num % 10)
            num //= 10
        d = d[::-1]
        to_replace = next((x for x in d if x != 9), None)
        high = replace(d, to_replace, 9)
        to_replace = d[0] if d[0] != 1 else next((x for x in d if x > 1), None)
        return high - replace(d, to_replace, to_replace == d[0])

