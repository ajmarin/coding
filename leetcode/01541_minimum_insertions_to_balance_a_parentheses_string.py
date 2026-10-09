class Solution:
    def minInsertions(self, s: str) -> int:
        ans = opened = 0
        expect_close = False
        for c in s:
            if c == "(":
                if expect_close:
                    ans += 1
                    expect_close = False
                else:
                    opened += 1
            elif c == ")":
                if expect_close:
                    opened -= 1
                    expect_close = False
                else:
                    expect_close = True
                    if not opened:
                        ans += 1
                        opened += 1
        return ans + 2 * opened - expect_close
