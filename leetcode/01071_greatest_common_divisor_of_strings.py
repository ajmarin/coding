class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        l1, l2 = len(str1), len(str2)
        if l1 < l2:
            l1, l2 = l2, l1
            str1, str2 = str2, str1

        def is_repeated(prefix: str, string: str) -> bool:
            return prefix * (len(string) // len(prefix)) == string

        for i in range(l2, 0, -1):
            if l2 % i or l1 % i:
                continue
            prefix = str2[:i]
            if is_repeated(prefix, str2) and is_repeated(prefix, str1):
                return prefix
        return ""
