class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.task_queue = []
        self.task_info = {}
        for uid, tid, priority in tasks:
            self.add(uid, tid, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        heappush(self.task_queue, (-priority, -taskId, userId))
        self.task_info[taskId] = (userId, -priority)

    def edit(self, taskId: int, newPriority: int) -> None:
        self.add(self.task_info[taskId][0], taskId, newPriority)

    def rmv(self, taskId: int) -> None:
        self.task_info[taskId] = (-1, -1)

    def execTop(self) -> int:
        while self.task_queue:
            p, t, u = heappop(self.task_queue)
            current_user, current_priority = self.task_info[-t]
            if current_priority == p and u == current_user:
                self.rmv(-t)
                return u
        return -1

