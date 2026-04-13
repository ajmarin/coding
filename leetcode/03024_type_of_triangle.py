class Solution:
    def triangleType(self, nums: List[int]) -> str:
        if nums[0] == nums[1] == nums[2]:
            return "equilateral"
        a, b, c = sorted(nums)
        if a + b <= c:
            return "none"
        return "isosceles" if a == b or b == c else "scalene"
