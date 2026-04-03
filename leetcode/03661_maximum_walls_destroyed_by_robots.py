LEFT = 0
RIGHT = 1


class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        dist_by_robot = {robots[i]: d for i, d in enumerate(distance)}
        robots.sort()
        walls.sort()

        def count_walls(left, right):
            return bisect_right(walls, right) - bisect_left(walls, left)

        n = len(robots)
        walls_left, walls_right = [], []

        for i in range(n):
            pos = robots[i]
            dist = dist_by_robot[pos]
            reach_left = max(pos - dist, -inf if i == 0 else robots[i - 1] + 1)
            walls_left.append(count_walls(reach_left, pos))
            reach_right = min(pos + dist, inf if i == n - 1 else robots[i + 1] - 1)
            walls_right.append(count_walls(pos, reach_right))

        prev = walls_left[0], walls_right[0]

        for i in range(1, n):
            wleft, wright = walls_left[i], walls_right[i]
            between = count_walls(robots[i - 1], robots[i])
            prev = [
                max(
                    prev[LEFT] + wleft,
                    prev[RIGHT]
                    - walls_right[i - 1]
                    + min(wleft + walls_right[i - 1], between),
                ),
                wright + max(prev),
            ]

        return max(prev)
