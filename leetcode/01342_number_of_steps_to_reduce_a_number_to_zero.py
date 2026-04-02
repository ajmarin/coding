class Solution:
    def numberOfSteps(self, num: int) -> int:
        for steps in range(64):
            if num == 0:
                break
            if num & 1:
                num -= 1
            else:
                num >>= 1
        return steps
