class Solution:
    def maxLength(self, arr: List[str]) -> int:
        answer = [0]
        strs = list(map(set, filter(lambda x: len(x) == len(set(x)), arr)))
        n = len(strs)
        def bt(current: set, index: int) -> int:
            if len(current) > answer[0]:
                answer[0] = len(current)
            for i in range(index, n):
                if not current & strs[i]:
                    bt(current | strs[i], i + 1)
        bt(set(), 0)
        return answer[0]