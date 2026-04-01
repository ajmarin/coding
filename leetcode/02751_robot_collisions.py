class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        right = deque([])
        for index in sorted(range(len(positions)), key=positions.__getitem__):
            if directions[index] == "R":
                right.append(index)
                continue
            while right:
                ir = right[-1]
                if healths[ir] == healths[index]:
                    right.pop()
                    healths[index] = healths[ir] = 0
                    break
                if healths[ir] > healths[index]:
                    healths[ir] -= 1
                    healths[index] = 0
                    break
                healths[ir] = 0
                right.pop()
                healths[index] -= 1
        return [*filter(None, healths)]
