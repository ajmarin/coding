class Solution:
    def digArtifacts(
        self, n: int, artifacts: List[List[int]], dig: List[List[int]]
    ) -> int:
        grid = [[0] * n for _ in range(n)]
        size = Counter()
        for idx, (r1, c1, r2, c2) in enumerate(artifacts, 1):
            for r in range(r1, r2 + 1):
                for c in range(c1, c2 + 1):
                    grid[r][c] = idx
            size[idx] = (r2 - r1 + 1) * (c2 - c1 + 1)
        ans = 0
        for r, c in dig:
            artifact_num = grid[r][c]
            size[artifact_num] -= 1
            ans += size[artifact_num] == 0
        return ans
