class Solution:
    def countDigitOne(self, n: int) -> int:
        digi = []
        while n:
            digi.append(n % 10)
            n //= 10
        @cache
        def f(i, one, leading, lim):
            if i == -1:
                return one
            res = 0
            if leading:
                res += f(i - 1, one, True, False)
            lo = 1 if leading else 0
            hi = digi[i] if lim else 9
            for x in range(lo, hi + 1):
                res += f(i - 1, one + (x == 1), False, lim and x == hi)
            return res
        return f(len(digi) - 1, 0, True, True)
