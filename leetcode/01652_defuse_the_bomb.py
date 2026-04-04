class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)

        def get_sum(a, b):
            if a > b:
                a, b = b, a
            return sum(code[i % n] for i in range(a, b + 1))

        if k > 0:
            return [get_sum(i + 1, i + k) for i in range(n)]
        if k < 0:
            return [get_sum(i - 1, i + k) for i in range(n)]
        return [0] * n
