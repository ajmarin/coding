ORDA = ord("a")


class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        mapping = dict((chr(i + ORDA), w) for i, w in enumerate(widths))
        curr_line, lines = 0, 1
        for c in s:
            w = mapping[c]
            curr_line += w
            if curr_line > 100:
                curr_line = w
                lines += 1
        return [lines, curr_line]
