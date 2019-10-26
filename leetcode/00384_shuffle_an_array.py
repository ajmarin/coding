class Solution:
    def __init__(self, nums: List[int]):
        self.orig = nums
        self.nums = nums.copy()

    def reset(self) -> List[int]:
        self.nums = self.orig.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        n = self.nums
        L = len(n)
        for i in range(L):
            j = i + int(random.random() * (L - i))
            n[i], n[j] = n[j], n[i]
        return n