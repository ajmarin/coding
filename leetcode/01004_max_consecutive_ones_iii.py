class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        N = len(A)
        best, left = 0, -1
        for right, is_one in enumerate(A):
            K -= not is_one
            if is_one or K > -1:
                best = max(best, right - left)
            else:
                left += 1
                while A[left]:
                    left += 1
        return best