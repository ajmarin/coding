class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        left = length = right = 0

        for right in range(len(words)):
            w = words[right]
            lw = len(w)
            if length + right - left + lw > maxWidth:
                if right - left == 1:
                    ans.append(words[left] + " " * (maxWidth - length))
                    left = right
                    length = 0
                else:
                    line_str = words[left]
                    gaps = right - left - 1
                    gap_size = (maxWidth - length) // gaps
                    rem = (maxWidth - length) % gaps
                    gap_strs = [" " * gap_size, " " * (gap_size + 1)]
                    for left in range(left + 1, right):
                        line_str += gap_strs[rem > 0] + words[left]
                        rem -= 1
                    ans.append(line_str)
                    length = 0
                    left = right
            length += lw
        last_line = " ".join(words[left:])
        ans.append(last_line + " " * (maxWidth - len(last_line)))
        return ans
