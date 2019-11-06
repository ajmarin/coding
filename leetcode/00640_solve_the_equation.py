class Solution:
    def solveEquation(self, equation: str) -> str:
        left, right = equation.split('=')
        def process(s: str) -> (int, int):
            has_x = False
            part = ''
            sign = 1
            oc, xc = 0, 0
            for c in s:
                if c not in {'-', '+'}:
                    if c == 'x':
                        has_x = True
                        part = part or '1'
                    else:
                        part += c
                else:
                    if part:
                        w = sign * int(part)
                        xc += w if has_x else 0
                        oc += 0 if has_x else w
                    part = ''
                    sign = 1 if c == '+' else -1
                    has_x = False
            if part:
                w = sign * int(part)
                xc += w if has_x else 0
                oc += 0 if has_x else w
            return xc, oc
        left = process(left)
        right = process(right)
        x = left[0] - right[0]
        c = left[1] - right[1]
        if not x and not c:
            return 'Infinite solutions'
        if not x:
            return 'No solution'
        return f'x={-c//x}'