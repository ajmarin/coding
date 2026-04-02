class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        odds = 0
        for n in arr:
            if n & 1:
                odds += 1
                if odds == 3:
                    return True
            else:
                odds = 0
        return False
