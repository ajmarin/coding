class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        N = len(A)
        A.sort()
        yield_index = [i for i in range(N)]
        answer = collections.deque()
        for num in B:
            index = bisect.bisect(A, num) % N
            while yield_index[index] != index:
                tmp = yield_index[index]
                yield_index[index] = yield_index[tmp]
                index = tmp
            yield_index[index] = (index + 1) % N
            answer.append(A[index])
        return answer