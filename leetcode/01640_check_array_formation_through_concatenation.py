class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        first_num_to_index = {p[0]: index for index, p in enumerate(pieces)}
        i, n = 0, len(arr)
        while i < n:
            num = arr[i]
            if num not in first_num_to_index:
                return False
            piece = pieces[first_num_to_index[num]]
            for j in range(i + 1, i + len(piece)):
                if arr[j] != piece[j - i]:
                    return False
            i += len(piece)
        return True
