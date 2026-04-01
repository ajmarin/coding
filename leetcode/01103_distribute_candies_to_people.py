class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        index = 0
        for count in range(1, 10**6):
            if candies >= count:
                ans[index] += count
                candies -= count
            else:
                ans[index] += candies
                candies = 0
                break
            index = (index + 1) % num_people
        return ans
