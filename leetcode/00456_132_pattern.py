class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s = []
        popped = -(10**9)
        for num in nums[::-1]:
            if num < popped:
                return True
            while s and num > s[-1]:
                popped = s.pop()
            s.append(num)
        return False
