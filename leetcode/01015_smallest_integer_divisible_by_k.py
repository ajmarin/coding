class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        i, rem = 1, 1 % k
        while rem:
            i += 1
            rem = ((10 * rem) + 1) % k
        return i
