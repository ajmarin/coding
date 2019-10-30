class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        answer, r = [], []
        for i in range(numRows):
            r = [x + (r[j - 1] if j else 0) for j, x in enumerate(r)] + [1]
            answer.append(r)
        return answer