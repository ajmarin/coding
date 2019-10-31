class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        t_by_name = collections.defaultdict(collections.deque)
        answer = set()
        for t in transactions:
            name, time, amount, city = t.split(',')
            amount = int(amount)
            time = int(time)
            t_by_name[name].append((time, amount, city))
            if amount > 1000:
                answer.add(t)
        for name, ts in t_by_name.items():
            for i, t1 in enumerate(ts):
                for j in range(i + 1, len(ts)):
                    t2 = ts[j]
                    if abs(t2[0] - t1[0]) <= 60 and t2[2] != t1[2]:
                        answer.add(','.join([name, *map(str, t2)]))
                        answer.add(','.join([name, *map(str, t1)]))
        return answer