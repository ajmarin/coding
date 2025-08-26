class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = max_diag = -1
        for w, h in dimensions:
            diag = w * w + h * h
            if diag > max_diag:
                max_diag = diag
                ans = w * h
            elif diag == max_diag:
                area = w * h
                ans = area if area > ans else ans
        return ans

