class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        pos = 0
        stack = collections.deque(range(min(9, n), 0, -1))
        answer = collections.deque()
        while stack:
            top = stack.pop()
            if top % 10:
                answer.append(top)
                x = top * 10
                while x <= n:
                    answer.append(x)
                    stack.append(x)
                    x *= 10
            else:
                stack.extend(range(min(top + 9, n), top, -1))
        return answer