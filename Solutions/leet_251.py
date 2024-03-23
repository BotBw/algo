class Vector2D:

    def __init__(self, vec: List[List[int]]):
        self.li = []
        self.id = 0
        for v in vec:
            self.li.extend(v)

    def next(self) -> int:
        v = self.li[self.id]
        self.id += 1
        return v

    def hasNext(self) -> bool:
        return self.id < len(self.li)


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(vec)
# param_1 = obj.next()
# param_2 = obj.hasNext()
