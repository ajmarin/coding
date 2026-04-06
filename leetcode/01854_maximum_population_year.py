class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        population = Counter()
        for birth, death in logs:
            population[birth] += 1
            population[death] -= 1
        highest = prev = 0
        ans = None
        for year in range(1950, 2051):
            curr = population[year] = population[year] + prev
            if curr > highest:
                ans = year
                highest = curr
            prev = curr
        return ans
