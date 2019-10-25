class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        top3 = set()
        for n in nums:
            top3.add(n)
            if len(top3) == 4:
                top3.remove(min(top3))
        return min(top3) if len(top3) == 3 else max(top3)