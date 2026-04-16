class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def dp(s: str) -> bool:
            if s == "":
                return True
            return any(s.startswith(w) and dp(s[len(w) :]) for w in wordDict)

        return dp(s)
