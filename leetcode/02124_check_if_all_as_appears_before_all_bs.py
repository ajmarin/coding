class Solution:
    def checkString(self, s: str) -> bool:
        return "b" not in s or s.rfind("a") < s.find("b")
