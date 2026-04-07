class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            temp = ""
            for start in range(0, len(s), k):
                temp += str(sum(map(int, s[start : start + k])))
            s = temp
        return s
