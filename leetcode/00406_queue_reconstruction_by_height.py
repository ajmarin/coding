class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort()
        people = [[h, exp, 0] for h, exp in people]
        answer = collections.deque()
        for _ in people:
            i = next(i for i, (_, expected, found) in enumerate(people) if expected == found)
            answer.append(people[i][:2])
            for j, (h, _, found) in enumerate(people):
                if h > people[i][0]:
                    break
                people[j][2] = found + 1
        return answer