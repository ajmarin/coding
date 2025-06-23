def is_palindrome(n: int, b: int) -> List[int]:
    digits = []
    while n:
        digits.append(n % b)
        n //= b
    return digits == digits[::-1]

class Solution:
    def kMirror(self, k: int, n: int) -> int:
        ans, low = 0, 1
        while True:
            for mode in ["odd", "even"]:
                for i in range(low, 10 * low):
                    pal = i
                    i = i // 10 if mode == "odd" else i
                    while i:
                        pal = 10 * pal + i % 10
                        i //= 10
                    if is_palindrome(pal, k):
                        ans += pal
                        if not (n := n - 1):
                            return ans
            low = 10 * low

