class Solution:
    def fractionAddition(self, expression: str) -> str:
        fractions = re.split('\+|\-', expression)
        num, denum, pos = 0, 1, 0
        def mcd(a, b):
            a, b = abs(a), abs(b)
            while a:
                a, b = b % a, a
            return a or b
        negative = expression[0] == '-'
        for f in fractions:
            if f:
                fn, fd = map(int, f.split('/'))
                fn = -fn if expression[pos - 1] == '-' else fn
                new_d = denum // mcd(denum, fd) * fd
                num = num * (new_d // denum) + fn * (new_d // fd)
                denum = new_d
            pos += len(f) + 1
        d = mcd(num, denum)
        return f'{num // d}/{denum // d}'