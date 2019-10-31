class Solution:
    def lengthLongestPath(self, input: str) -> int:
        max_len = 0
        path_len = {-1: 0}
        for line in input.split('\n'):
            dir_or_file = line.lstrip('\t')
            L = len(dir_or_file)
            depth = len(line) - L
            if dir_or_file.find('.') != -1:
                max_len = max(max_len, L + path_len[depth - 1])
            else:
                path_len[depth] = L + 1 + path_len[depth - 1]
        return max_len