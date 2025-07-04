def count_bits(n: int) -> int:
    count = 0
    while n:
        n &= (n - 1)
        count += 1
    return count

class Solution:
    def kthCharacter(self, k: int) -> str:
        return chr(ord('a') + count_bits(k - 1))

