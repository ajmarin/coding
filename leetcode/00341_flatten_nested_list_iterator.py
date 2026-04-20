class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.iters = [[nestedList, 0]]
        self.update()

    def update(self):
        s = self.iters
        while s:
            top = s[-1]
            nested_list, index = top
            if index == len(nested_list):
                s.pop()
                continue
            if nested_list[index].isInteger():
                return True
            top[1] += 1
            s.append([nested_list[index].getList(), 0])
        return False

    def next(self) -> int:
        top_iter, i = self.iters[-1]
        self.iters[-1][1] += 1
        return top_iter[i].getInteger()

    def hasNext(self) -> bool:
        return self.update()
