class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.max_pos = self.pos = 0

    def visit(self, url: str) -> None:
        self.pos += 1
        self.max_pos = self.pos
        if self.pos >= len(self.history):
            self.history.append(url)
        else:
            self.history[self.pos] = url

    def back(self, steps: int) -> str:
        self.pos = max(0, self.pos - steps)
        return self.history[self.pos]

    def forward(self, steps: int) -> str:
        self.pos = min(self.max_pos, self.pos + steps)
        return self.history[self.pos]
