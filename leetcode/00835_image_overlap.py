class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)

        def collect_ones(img: List[List[int]]):
            ones = []
            for i, row in enumerate(img):
                for j in range(n):
                    if row[j]:
                        ones.append((i, j))
            return ones

        ones1 = collect_ones(img1)
        ones2 = collect_ones(img2)
        return max(
            Counter(
                (x1 - x2, y1 - y2) for x1, y1 in ones1 for x2, y2 in ones2
            ).values(),
            default=0,
        )
