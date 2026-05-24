class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)

        @cache
        def dp(index: int) -> int:
            res = 1
            pivot = arr[index]
            for i in range(index - 1, max(index - d, 0) - 1, -1):
                if pivot <= arr[i]:
                    break
                cand = dp(i)
                res = res if res > cand + 1 else cand + 1
            for i in range(index + 1, min(n, index + d + 1)):
                if pivot <= arr[i]:
                    break
                cand = dp(i)
                res = res if res > cand + 1 else cand + 1
            return res

        return max(dp(i) for i in range(n))
