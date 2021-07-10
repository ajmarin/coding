from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        ans = 0

        busy = defaultdict(set)
        for row, seat in reservedSeats:
            busy[row].add(seat)

        for row, busy_seats in busy.items():
            empty = 0
            for seat in range(1, 11):
                if seat in busy_seats:
                    empty = 0
                    continue
                if seat % 4 == 0:
                    empty = 2 if empty >= 2 else 0
                empty += 1
                if empty == 4:
                    ans += 1
                    empty = 0
        return ans + 2 * (n - len(busy))

