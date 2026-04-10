class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        l1, l2, l3 = len(s1), len(s2), len(s3)
        min_len = min(len(s1), len(s2), len(s3))
        for i in range(min_len):
            if s1[i] != s2[i] or s1[i] != s3[i]:
                break
        else:
            return l1 + l2 + l3 - 3 * min_len
        return -1 if i == 0 else l1 + l2 + l3 - 3 * i
