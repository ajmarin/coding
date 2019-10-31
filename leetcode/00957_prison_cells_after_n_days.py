class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        L = len(cells)
        mask = sum(zero_or_one << i for i, zero_or_one in enumerate(cells[::-1]))
        mask_to_day = {mask: 0}
        day_to_mask = [0] * (1 << L)
        day_to_mask[0] = mask
        for day in range(1, min(1 << L, N + 1)):
            new_mask = 0
            left, right = 0x4, 0x1
            and_mask = 0x5
            for i in range(1, L - 1):
                if not ((mask & left) >> 2) ^ (mask & right):
                    new_mask |= 1 << i
                and_mask <<= 1
                left <<= 1
                right <<= 1
            if new_mask in mask_to_day:
                break
            mask_to_day[new_mask] = day
            day_to_mask[day] = new_mask
            mask = new_mask
        if day == N:
            dayN_mask = new_mask
        else:
            cycle_start = mask_to_day[new_mask]
            cycle_size = day - cycle_start
            dayN_mask = day_to_mask[cycle_start + ((N - cycle_start) % cycle_size)]
        return [1 if 1 << (L - i - 1) & dayN_mask else 0 for i in range(L)]