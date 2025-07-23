class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        first, second = "ab", "ba"
        if x < y:
            first, second = second, first
            x, y = y, x

        def remove(s: str, target: str):
            stack = []
            f, w = target
            prev = -1
            for c in s:
                if prev == f and c == w:
                    stack.pop()
                    prev = -1 if not stack else stack[-1]
                else:
                    prev = c
                    stack.append(c)
            rem = "".join(stack)
            return rem, (len(s) - len(rem)) // 2

        s, removals = remove(s, first)
        return x * removals + y * remove(s, second)[1]

