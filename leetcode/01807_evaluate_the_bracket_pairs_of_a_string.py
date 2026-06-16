class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        mapping = dict(knowledge)
        ans = ""
        it = iter(s)
        for c in it:
            if c != "(":
                ans += c
                continue
            key = ""
            while (c := next(it)) != ")":
                key += c
            ans += mapping.get(key, "?")
        return ans
