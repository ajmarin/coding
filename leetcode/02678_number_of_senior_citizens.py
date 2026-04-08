class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return len([1 for d in details if int(d[11:13]) > 60])
