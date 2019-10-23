class Solution:
    def moveZeroes(self, n: List[int]) -> None:
        zero = None
        for i, x in enumerate(n):
            if (zero is None) ^ (x != 0):
                if x:
                    n[i], n[zero] = n[zero], n[i]
                    while n[zero]:
                        zero += 1
                else:
                    zero = i