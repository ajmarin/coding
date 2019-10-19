class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        answer = []
        factorial = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
        nums = [i + 1 for i in range(n)]

        n -= 1
        while k > 1:
            pos = (k + factorial[n] - 1) // factorial[n]
            count = 0
            for i in range(len(nums)):
                if nums[i] != -1:
                    count += 1
                    if count == pos:
                        answer.append(nums[i])
                        nums[i] = -1
                        break
            k -= (pos - 1) * factorial[n]
            n -= 1
        answer.extend([x for x in nums if x != -1])
        return ''.join(map(str, answer))