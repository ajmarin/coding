class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i, top, j = 0, -1, 0
        L = len(pushed)
        while i < L:
            if top >= 0 and pushed[top] == popped[j]:
                top -= 1
                j += 1
            else:
                top += 1
                pushed[top] = pushed[i]
                i += 1
        while j < L:
            if popped[j] != pushed[top]:
                return False
            j += 1
            top -= 1
        return True