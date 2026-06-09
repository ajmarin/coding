@cache
def get_closest_divs(n: int) -> [int, int]:
    for d in range(isqrt(n), 0, -1):
        if n % d == 0:
            return [d, n // d]


class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        np1 = get_closest_divs(num + 1)
        np2 = get_closest_divs(num + 2)
        return np1 if np1[1] - np1[0] < np2[1] - np2[0] else np2
