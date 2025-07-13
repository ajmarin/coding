class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        ans = ti = 0
        n = len(trainers)
        for p in players:
            while ti < n and trainers[ti] < p: ti += 1
            if ti == n: break
            ans += 1
            ti += 1
        return ans

