class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        if n < 3:
            return False

        def test(i: int, j: int) -> bool:
            if num[0] == "0" and i > 1 or j - i > 1 and num[i] == "0":
                return False
            a, b = int(num[:i]), int(num[i:j])
            t = num[j:]
            while t:
                a, b = b, a + b
                strb = str(b)
                if not t.startswith(strb):
                    return False
                t = t[len(strb) :]
            return True

        return any(test(i, j) for i in range(1, n) for j in range(i + 1, n))
