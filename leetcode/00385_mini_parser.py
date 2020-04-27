class Solution:
    def fixValue(self, value: int, negative: bool):
        return NestedInteger(value if not negative else -value)

    def deserialize(self, s: str, nlist: NestedInteger = None) -> NestedInteger:
        stack = collections.deque()
        ret = None
        zero = ord('0')
        negative, value = False, None
        for i, c in enumerate(s):
            if c >= '0' and c <= '9':
                value = 10 * (value or 0) + ord(c) - zero
            elif c == '-':
                negative = True
            elif c == '[':
                stack.append(NestedInteger())
            elif c == ',':
                if value is not None:
                    stack[-1].add(self.fixValue(value, negative))
                    negative, value = False, None
            elif c == ']':
                if value is not None:
                    stack[-1].add(self.fixValue(value, negative))
                    negative, value = False, None
                ret = stack.pop()
                if len(stack):
                    stack[-1].add(ret)
        return ret or self.fixValue(value, negative)