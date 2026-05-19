def is_binary_palindrome(n: int) -> bool:
    s = bin(n)[2:]
    return all(s[i] == s[~i] for i in range(len(s) // 2))


PALINDROMES = [i for i in range(1, 6001) if is_binary_palindrome(i)]


class Solution:
    def minOperations(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            index = bisect_right(PALINDROMES, n)
            ans.append(min(n - PALINDROMES[index - 1], PALINDROMES[index] - n))
        return ans
