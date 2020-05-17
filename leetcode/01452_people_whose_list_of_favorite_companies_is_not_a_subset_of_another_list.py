class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        sets = list(map(set, favoriteCompanies))
        answer = []
        for i in range(len(sets)):
            for j in range(len(sets)):
                if i == j:
                    continue
                if not len(sets[i] - sets[j]):
                    break
            else:
                answer.append(i)
        return answer