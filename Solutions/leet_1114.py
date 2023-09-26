# Solution 1
class Foo:
    def __init__(self):
        self.t = 0
    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.t = 1
    def second(self, printSecond: 'Callable[[], None]') -> None:
        while self.t != 1: 
            pass
        printSecond()
        self.t = 2
    def third(self, printThird: 'Callable[[], None]') -> None:
        while self.t != 2: 
            pass
        printThird()
# Solution 2
from time import sleep
class Foo:
    def __init__(self):
        self.t = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.t = 1

    def second(self, printSecond: 'Callable[[], None]') -> None:
        while self.t != 1: 
            sleep(1e-3)
        printSecond()
        self.t = 2

    def third(self, printThird: 'Callable[[], None]') -> None:
        while self.t != 2: 
            sleep(1e-3)
        printThird()

# Solution 2
from threading import Lock
class Foo:
    def __init__(self):
        self.l1 = Lock()
        self.l2 = Lock()
        self.l1.acquire()
        self.l2.acquire()
    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.l1.release()
    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.l1.acquire()
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.l1.release()
        self.l2.release()
    def third(self, printThird: 'Callable[[], None]') -> None:
        self.l2.acquire()
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        self.l2.release()

# Solution 3
from threading import Lock
class Foo:
    def __init__(self):
        self.l1 = Lock()
        self.l2 = Lock()
        self.l1.acquire()
        self.l2.acquire()
    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.l1.release()
    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.l1:
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
        self.l2.release()
    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.l2:
            # printThird() outputs "third". Do not change or remove this line.
            printThird()
