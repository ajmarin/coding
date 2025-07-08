class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        ans = 0
        for i in range(k):
            to_add = happiness[i] - i
            if to_add <= 0:
                break
            ans += to_add
        return ans

