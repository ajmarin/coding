class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        after = [0] * n

        prev, score = -1, 0
        for i in range(n - 1, -1, -1):
            score = score + 1 if security[i] <= prev else 0
            after[i] = score
            prev = security[i]

        prev, score = -1, 0
        ans = []
        for i, sec in enumerate(security):
            score = score + 1 if sec <= prev else 0
            if score >= time and after[i] >= time:
                ans.append(i)
            prev = sec
        return ans
