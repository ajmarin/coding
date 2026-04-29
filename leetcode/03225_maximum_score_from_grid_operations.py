class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        pfx = [[*(accumulate(col, initial=0))] for col in zip(*grid)]
        prev_max = [[0] * (n + 1) for _ in range(n + 1)]
        prev_sfx = [[0] * (n + 1) for _ in range(n + 1)]

        cdp = [[0] * (n + 1) for _ in range(n + 1)]
        p_pfx = pfx[0]
        for c in range(1, n):
            cdp[:] = [[0] * (n + 1) for _ in range(n + 1)]
            my_pfx = pfx[c]
            for h in range(n + 1):
                cdph = cdp[h]
                for prev_h in range(n + 1):
                    if h <= prev_h:
                        bonus = my_pfx[prev_h] - my_pfx[h]
                        cdph[prev_h] = max(cdph[prev_h], prev_sfx[prev_h][0] + bonus)
                    else:
                        bonus = p_pfx[h] - p_pfx[prev_h]
                        cdph[prev_h] = max(
                            cdph[prev_h],
                            prev_sfx[prev_h][h],
                            prev_max[prev_h][h] + bonus,
                        )
            p_pfx = my_pfx

            for h in range(n + 1):
                pmmh = prev_max[h]
                cdph = cdp[h]
                pmmh[0] = cdph[0]
                for prev_h in range(1, n + 1):
                    drop = my_pfx[prev_h] - my_pfx[h] if prev_h > h else 0
                    pmmh[prev_h] = max(pmmh[prev_h - 1], cdph[prev_h] - drop)
                psmh = prev_sfx[h]
                psmh[n] = cdph[n]
                for prev_h in range(n - 1, -1, -1):
                    psmh[prev_h] = max(psmh[prev_h + 1], cdph[prev_h])

        return max(*cdp[0], *cdp[n])
