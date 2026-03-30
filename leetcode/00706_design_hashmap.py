MAX_LEN = 10000


class Node:
    def __init__(self, key: int = -1, value: int = -1):
        self.key = key
        self.value = value
        self.next = None


class MyHashMap:
    def __init__(self):
        self.map = [Node() for _ in range(MAX_LEN)]

    def get_container(self, num: int) -> List[Node]:
        key = num % MAX_LEN
        return self.map[key]

    def put(self, key: int, value: int) -> None:
        head = self.get_container(key)
        while head.next:
            head = head.next
            if head.key == key:
                head.value = value
                return
        head.next = Node(key, value)

    def get(self, key: int) -> int:
        head = self.get_container(key)
        while head.next:
            head = head.next
            if head.key == key:
                return head.value
        return -1

    def remove(self, key: int) -> None:
        head = self.get_container(key)
        while head.next:
            if head.next.key == key:
                head.next = head.next.next
                return
            head = head.next
