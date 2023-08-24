class Solution:
    def findIntegers(self, n: int) -> int:
        digi = []
        while n:
            digi.append(n % 2)
            n //= 2
        
        @cache
        def f(i, prev, leading, lim):
            if i == -1:
                return not leading
            res = 0
            if leading:
                res += f(i - 1, False, True, False)
            lo = 1 if leading else 0
            hi = digi[i] if lim else 1
            for x in range(lo, hi + 1):
                if x == 1:
                    if not prev:
                        res += f(i - 1, True, False, lim and x == hi)
                else:
                    res += f(i - 1, False, False, lim and x == hi)
            return res
        
        return f(len(digi) - 1, False, True, True) + 1
