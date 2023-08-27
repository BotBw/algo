from array import *
from ast import *
from bisect import *
from collections import *
from functools import *

class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        digi = []
        nn = n
        while n:
            digi.append(n % 10)
            n //= 10

        @cache
        def f(i, set, leading, lim):
            if i == -1:
                return not leading
            res = 0
            if leading:
                res += f(i - 1, set, True, False)
            lo = 1 if leading else 0
            hi = digi[i] if lim else 9
            for x in range(lo, hi + 1):
                if not ((set >> x) & 1):
                    res += f(i - 1, set | 1 << x, False, lim and x == digi[i])
            return res
        
        return nn - f(len(digi) - 1, 0, True, True)