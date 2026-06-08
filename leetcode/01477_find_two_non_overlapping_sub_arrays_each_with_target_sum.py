class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        best = [n + 1] * n
        ans = curr_best = n + 1
        left, s = -1, 0
        for right, x in enumerate(arr):
            s += x
            while s > target:
                s -= arr[left := left + 1]
            if s == target:
                l = right - left
                curr_best = l if l < curr_best else curr_best
                if left != -1 and best[left] <= n:
                    ans = ans if ans < best[left] + l else best[left] + l
            best[right] = curr_best
        return -(ans > n) | ans
