OUT_OF_BOUNDS = 1<<31
ORD0 = ord('0')

def get_num(num: str, left: int, right: int):
    if num[left] == '0' and right - left > 1:
        return OUT_OF_BOUNDS
    r = 0
    for c in range(left, min(right, len(num))):
        r = r * 10 + ord(num[c]) - ORD0
    return r

class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        n = len(num)
        for i in range(1, n + 1):
            first = get_num(num, 0, i)
            if first >= OUT_OF_BOUNDS:
                break
            for j in range(i + 1, n - i + 1):
                second = get_num(num, i, j)
                if second >= OUT_OF_BOUNDS:
                    break
                ans = [first, second]
                while j < n:
                    total = first + second
                    if total >= OUT_OF_BOUNDS:
                        break
                    wanted = str(total)
                    if not num[j:].startswith(wanted):
                        break
                    j += len(wanted)
                    ans.append(total)
                    first, second = second, total
                if j == n and len(ans) > 2:
                    return ans
                first = ans[0]
        return []

