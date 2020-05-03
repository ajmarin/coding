class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        cities, sources = set(), set()
        for a, b in paths:
            cities.add(a)
            cities.add(b)
            sources.add(a)
        return (cities - sources).pop()