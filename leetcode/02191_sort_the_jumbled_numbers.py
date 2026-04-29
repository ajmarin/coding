class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def map_num(num: int) -> int:
            if num < 10:
                return mapping[num]
            power, res = 1, 0
            while num:
                res += power * mapping[num % 10]
                num //= 10
                power *= 10
            return res

        return sorted(nums, key=map_num)
