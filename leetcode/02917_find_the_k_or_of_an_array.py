class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        bit_count = [0] * 32
        for n in nums:
            for i in range(32):
                bit_count[i] += n & 1
                n >>= 1
                if n == 0:
                    break
        return sum(1 << i for i in range(32) if bit_count[i] >= k)
