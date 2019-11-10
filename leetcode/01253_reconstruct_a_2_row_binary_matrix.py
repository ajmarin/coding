class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        certain1 = sum(cs == 2 for cs in colsum)
        either = sum(cs == 1 for cs in colsum)
        if either + 2 * certain1 != upper + lower:
            return []
        if lower < certain1 or upper < certain1:
            return []
        upper -= certain1
        lower -= certain1
        answer = [[0] * len(colsum) for _ in (1, 2)]
        for j, cs in enumerate(colsum):
            if cs == 2:
                answer[0][j] = 1
                answer[1][j] = 1
            elif cs == 1:
                if upper > 0:
                    upper -= 1
                    answer[0][j] = 1
                elif lower > 0:
                    lower -= 1
                    answer[1][j] = 1
                else:
                    return []
        return answer