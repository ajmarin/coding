class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        def ones(n: int):
            cnt = 0
            while n:
                cnt += n & 1
                n >>= 1
            return cnt
        answer = []
        for mask in range(1<<10):
            if ones(mask) == num:
                hour = mask >> 6
                mins = mask & 0x3F
                if hour < 12 and mins < 60:
                    answer.append(f'{hour}:{mins:02d}')
        return answer