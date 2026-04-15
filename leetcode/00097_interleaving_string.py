class Solution:
    @cache
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False
        return (
            s1 == s2 == s3
            or (len(s1) and s1[0] == s3[0] and self.isInterleave(s1[1:], s2, s3[1:]))
            or (len(s2) and s2[0] == s3[0] and self.isInterleave(s1, s2[1:], s3[1:]))
        )
