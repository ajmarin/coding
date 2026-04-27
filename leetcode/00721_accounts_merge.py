class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        email_to_id = {}

        parent = list(range(n))

        def find(a):
            if a == parent[a]:
                return a
            parent[a] = find(parent[a])
            return parent[a]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return False
            parent[pa] = pb
            return True

        names = []
        for i, acc in enumerate(accounts):
            name, *emails = acc
            names.append(name)
            for email in emails:
                if email not in email_to_id:
                    email_to_id[email] = i
            id0 = email_to_id[emails[0]]
            for email in emails[1:]:
                union(id0, email_to_id[email])

        grouped_accounts = defaultdict(list)
        for email, eid in email_to_id.items():
            grouped_accounts[find(eid)].append(email)

        ans = []
        for account_id, emails in grouped_accounts.items():
            emails.sort()
            ans.append([names[account_id]] + emails)
        return ans
