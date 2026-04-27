class Solution:
    def getImportance(self, employees: List[Employee], id: int) -> int:
        id_to_emp = {e.id: e for e in employees}
        ans, q = 0, deque([id])
        while q:
            emp = id_to_emp[q.popleft()]
            ans += emp.importance
            q.extend(emp.subordinates)
        return ans
