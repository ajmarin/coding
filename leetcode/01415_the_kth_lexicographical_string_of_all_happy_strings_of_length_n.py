happy = {1: ["a", "b", "c"]}


def gen_happy(size: int):
    ans = []
    for s in happy[size - 1]:
        last = s[-1]
        for c in ["a", "b", "c"]:
            if c != last:
                ans.append(s + c)
        if len(ans) > 100:
            break
    return ans


for i in range(2, 11):
    happy[i] = gen_happy(i)


class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        hn = happy[n]
        return hn[k - 1] if k <= len(hn) else ""
