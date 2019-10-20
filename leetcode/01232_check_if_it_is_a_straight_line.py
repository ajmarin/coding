class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        dx, dy = coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]
        for i in range(2, len(coordinates)):
            ddx, ddy = coordinates[i][0] - coordinates[0][0], coordinates[i][1] - coordinates[0][1]
            if ddx * dy != ddy * dx:
                return False
        return True