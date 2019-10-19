class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        answer = []
        combination = [0] * k
        def solve(index: int, minv: int):
            if index == k:
                answer.append(combination.copy())
                return
            for i in range(minv, n):
                combination[index] = i + 1
                solve(index + 1, i + 1)
        solve(0, 0)
        return answer