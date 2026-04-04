class Solution:
    def minOperations(self, logs: List[str]) -> int:
        depth = 0
        for op in logs:
            if op == "./":
                continue
            if op == "../":
                depth = max(depth - 1, 0)
            else:
                depth += 1
        return depth
