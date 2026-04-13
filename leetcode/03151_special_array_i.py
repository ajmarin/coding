class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        prev_parity = 2
        for n in nums:
            parity = n & 1
            if parity == prev_parity:
                return False
            prev_parity = parity
        return True
