class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        dominoes = f"L{dominoes}R"
        mv = [(i, c) for i, c in enumerate(dominoes) if c != '.']
        res = list(dominoes)
        for (left, a), (right, b) in zip(mv, mv[1:]):
            if a < b: continue
            while left < right:
                res[left] = a
                res[right] = b
                left += 1
                right -= 1
            if a == b: res[left] = a
        return "".join(res[1:-1])

