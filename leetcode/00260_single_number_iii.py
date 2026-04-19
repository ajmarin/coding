class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for n in nums:
            xor ^= n

        bit = xor & -xor
        res = [0, 0]
        for n in nums:
            res[bit & n == 0] ^= n
        return res
