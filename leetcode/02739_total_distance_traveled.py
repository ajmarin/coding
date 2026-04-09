class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        ans = used = 0
        while mainTank:
            ans += mainTank
            used += mainTank
            mainTank = min(used // 5, additionalTank)
            used %= 5
            additionalTank -= mainTank
        return ans * 10
