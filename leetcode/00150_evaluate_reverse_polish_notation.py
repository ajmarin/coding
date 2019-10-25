class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = collections.deque()
        for t in tokens:
            if len(t) > 1 or ('0' <= t[0] <= '9'):
                s.append(int(t))
                continue
            op2 = s.pop()
            op1 = s.pop()
            if t == '+':
                s.append(op1 + op2)
            elif t == '*':
                s.append(op1 * op2)
            elif t == '/':
                s.append(int(op1 / op2))
            else:
                s.append(op1 - op2)
        return s.pop()