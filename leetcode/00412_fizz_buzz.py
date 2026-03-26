def mapnum(x: int) -> str:
    if x % 15 == 0:
        return "FizzBuzz"
    if x % 3 == 0:
        return "Fizz"
    if x % 5 == 0:
        return "Buzz"
    return str(x)


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        return [*map(mapnum, range(1, n + 1))]
