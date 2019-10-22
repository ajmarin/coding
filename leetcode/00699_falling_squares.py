class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ih = [None]*len(positions)
        answer = [0]*len(positions)
        ihp, max_height = 0, 0
        for x, side in positions:
            y = x + side
            current_height = 0
            for i in range(ihp):
                left, right, height = ih[i]
                if not (right <= x or y <= left):
                    current_height = max(current_height, height)
            current_height += side
            max_height = max(current_height, max_height)
            answer[ihp] = max_height
            ih[ihp] = x, y, current_height
            ihp += 1
        return answer