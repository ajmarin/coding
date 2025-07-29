class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        visits = defaultdict(int)
        for cpdomain in cpdomains:
            reps, domain = cpdomain.split(" ")
            reps = int(reps)
            pos = domain.find('.') + 1
            visits[domain] += reps
            while pos:
                visits[domain[pos:]] += reps
                pos = domain.find('.', pos) + 1
        return [f"{visits} {path}" for path, visits in visits.items()]

