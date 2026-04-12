class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        indices = []
        ans = [0] * len(temperatures)
        for i, t in enumerate(temperatures):
            while indices and temperatures[indices[-1]] < t:
                idx = indices.pop()
                ans[idx] = i - idx
            indices.append(i)
        return ans
