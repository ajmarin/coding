class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        N = len(A)
        answer = 0
        flip_index = collections.deque()
        flipped = False
        for i, n in enumerate(A):
            if len(flip_index) and i == flip_index[0]:
                flipped = not flipped
                flip_index.popleft()
            if not(n ^ flipped):
                flip_ends = i + K
                if flip_ends > N:
                    return -1
                answer += 1
                flipped = not flipped
                flip_index.append(flip_ends)
        return answer