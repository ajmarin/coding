class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        ends = sorted((e, v) for _, e, v in events)
        ends.append((-1, 0))

        ans, best_prior = 0, 0
        index = 0
        end_time, prior_value = ends[index]
        for start, value in sorted((s, v) for s, _, v in events):
            while end_time < start:
                best_prior = max(best_prior, prior_value)
                index += 1
                end_time, prior_value = ends[index]
            ans = max(ans, best_prior + value)
        return ans

