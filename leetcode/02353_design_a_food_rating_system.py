class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisines = defaultdict()
        self.cuisine_rates = defaultdict(SortedList)
        self.rates = defaultdict()

        for f, c, r in zip(foods, cuisines, ratings):
            self.cuisines[f] = c
            self.cuisine_rates[c].add((-r, f))
            self.rates[f] = -r

    def changeRating(self, food: str, newRating: int) -> None:
        rates = self.cuisine_rates[self.cuisines[food]]
        rates.discard((self.rates[food], food))
        rates.add((-newRating, food))
        self.rates[food] = -newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cuisine_rates[cuisine][0][1]

