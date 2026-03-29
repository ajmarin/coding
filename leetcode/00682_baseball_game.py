class Solution:
    def calPoints(self, operations: List[str]) -> int:
        values = deque()
        for op in operations:
            if op == "+":
                values.append(values[-1] + values[-2])
            elif op == "D":
                values.append(values[-1] << 1)
            elif op == "C":
                values.pop()
            else:
                values.append(int(op))
        return sum(values)
