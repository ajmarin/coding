class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        answer = []
        n = 1
        while n <= label:
            n <<= 1
        while label:
            answer.append(label)
            label = ((n - label - 1) >> 1) + (n >> 2)
            n >>= 1
        return answer[::-1]