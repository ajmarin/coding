def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        cnt = Counter()
        for num in range(lowLimit, highLimit + 1):
            cnt[digit_sum(num)] += 1
        return max(cnt.values())
