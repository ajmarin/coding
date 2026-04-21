class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        return pow(a, int("".join(map(str, b))), mod=1337)
