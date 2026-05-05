total_apples = [0]
apples = i = 0
while apples < 10**15:
    i += 1
    apples += 12 * i * i
    total_apples.append(apples)


class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        return 8 * bisect_left(total_apples, neededApples)
