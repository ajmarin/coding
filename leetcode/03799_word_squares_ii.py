TOP, LEFT, RIGHT, BOT = range(4)


class Solution:
    def wordSquares(sqf, words: List[str]) -> List[List[str]]:
        n = len(words)
        used = [False] * n
        ans = []

        def bt(i: int, sq=[]):
            if i == 2:
                if sq[TOP][0] != sq[LEFT][0]:
                    return
            elif i == 3:
                if sq[TOP][3] != sq[RIGHT][0]:
                    return
            elif i == 4:
                if sq[LEFT][3] == sq[BOT][0] and sq[BOT][3] == sq[RIGHT][3]:
                    ans.append(sq.copy())
                return
            for k in range(n):
                if used[k]:
                    continue
                used[k] = True
                sq[i] = words[k]
                bt(i + 1, sq)
                used[k] = False

        bt(0, [""] * 4)
        ans.sort()
        return ans
