class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        sign = lambda s: 1 if s > 0 else -1
        for n in asteroids:
            if n > 0 or not stack or sign(stack[-1]) == sign(n):
                stack.append(n)
            else:
                while stack and sign(stack[-1]) == 1 and -stack[-1] > n:
                    stack.pop()
                if stack and -stack[-1] == n:
                    stack.pop()
                    continue
                if not stack or sign(stack[-1]) == -1:
                    stack.append(n)
        return stack
