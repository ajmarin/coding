class Solution:
    def __init__(self, n_rows: int, n_cols: int):
        self.rows = n_rows
        self.cols = n_cols
        self.seen = set()

    def flip(self) -> List[int]:
        while True:
            position = random.randint(0, self.rows * self.cols - 1)
            if position not in self.seen:
                self.seen.add(position)
                break
        return position // self.cols, position % self.cols

    def reset(self) -> None:
        self.seen = set()