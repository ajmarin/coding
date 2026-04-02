def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def countLargestGroup(self, n: int) -> int:
        counts = Counter(map(digit_sum, range(1, n + 1)))
        highest = max(counts.values())
        return sum(v == highest for v in counts.values())
