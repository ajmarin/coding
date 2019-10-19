class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = [p for p in path.split('/') if p and p != '.']
        answer = [None] * len(parts)
        index = 0
        for part in parts:
            if part == '..':
                if index:
                    index -= 1
            else:
                answer[index] = part
                index += 1
        return '/' + '/'.join(answer[:index])