class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        sequences = collections.deque()
        for n in nums:
            found = False
            pop = 0
            for i, (s, size) in enumerate(sequences):
                if s < n:
                    pop += 1
                elif s == n:
                    sequences[i] = (n + 1, size + 1)
                    found = True
                    break
            while pop:
                _, size = sequences.pop()
                pop -= 1
                if size < 3:
                    return False
            if not found:
                sequences.appendleft((n + 1, 1))
        return all(size >= 3 for _, size in sequences)