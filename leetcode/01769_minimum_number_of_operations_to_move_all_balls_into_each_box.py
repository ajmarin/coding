class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        balls = prev = 0
        suffix = [0] * n
        for i in range(n - 1, -1, -1):
            prev = suffix[i] = balls + prev
            balls += boxes[i] == "1"
        balls = prev = 0
        ans = [0] * n
        for i in range(n):
            ans[i] = suffix[i] + prev
            balls += boxes[i] == "1"
            prev += balls
        return ans
