class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        heaters += [10**10]
        curr_heater, prev_heater = heaters[0], -(10**9)
        ans, h, hidx = 0, len(heaters), 1
        for house in houses:
            while house > curr_heater:
                prev_heater, curr_heater = curr_heater, heaters[hidx]
                hidx += 1
            ans = max(ans, min(house - prev_heater, curr_heater - house))
        return ans
