class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        answer = 0
        used = collections.Counter()
        for value, label in sorted(zip(values, labels), reverse=True):
            used[label] += 1
            if used[label] <= use_limit:
                num_wanted -= 1
                answer += value
                if not num_wanted:
                    break
        return answer