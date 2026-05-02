VALID = {2, 5, 6, 9}
good, seen = set(), set()


def generate(num: int, valid: int):
    if num > 10000 or num in seen:
        return
    seen.add(num)
    if valid:
        good.add(num)
    for d in (0, 1, 2, 5, 6, 8, 9):
        generate(num * 10 + d, valid | (d in VALID))


generate(0, False)
good = sorted(good)


class Solution:
    def rotatedDigits(self, n: int) -> int:
        return bisect_right(good, n)
