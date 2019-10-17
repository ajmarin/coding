class Solution:
    def isValid(self, s: str) -> bool:
        expect = []
        for c in s:
            if c == '(':
                expect.append(')')
            elif c == '[':
                expect.append(']')
            elif c == '{':
                expect.append('}')
            elif len(expect) == 0 or expect.pop() != c:
                return False
        return len(expect) == 0