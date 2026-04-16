class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans = []

        @cache
        def is_palindrome(cand: str) -> bool:
            return all(cand[i] == cand[~i] for i in range(len(cand) // 2))

        def bt(pos: int, curr: str, palindromes: List[str]):
            if pos == n:
                if is_palindrome(curr):
                    ans.append(palindromes[:] + [curr])
                return
            if curr and is_palindrome(curr):
                palindromes.append(curr)
                bt(pos + 1, s[pos], palindromes)
                palindromes.pop()
            bt(pos + 1, curr + s[pos], palindromes)

        bt(0, "", [])
        return ans
