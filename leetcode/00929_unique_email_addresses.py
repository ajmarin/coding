class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set = set()
        for email in emails:
            local, domain = email.split("@")
            if len(domain) < 5 or not domain.endswith(".com"):
                continue
            local_before, *_ = local.partition("+")
            cleaned_local = local_before.replace(".", "")
            email_set.add(f"{cleaned_local}@{domain}")
        return len(email_set)
