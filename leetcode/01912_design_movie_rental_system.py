class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.rented = SortedList()
        self.by_movie = defaultdict(SortedList)
        self.prices = {}
        for shop, movie, price in entries:
            self.by_movie[movie].add((price, shop))
            self.prices[shop, movie] = price

    def search(self, movie: int) -> List[int]:
        return [*map(itemgetter(1), self.by_movie[movie][:5])]

    def rent(self, shop: int, movie: int) -> None:
        price = self.prices[shop, movie]
        self.by_movie[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.prices[shop, movie]
        self.rented.remove((price, shop, movie))
        self.by_movie[movie].add((price, shop))

    def report(self) -> List[List[int]]:
        return [(shop, movie) for _, shop, movie in self.rented[:5]]

