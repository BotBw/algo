class Solution:
    def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        def f(n):
            digi = []
            while n:
                digi.append(n % 10)
                n //= 10
            @cache
            def _f(i, mod, odd, even, leading, lim):
                if i == -1:
                    return (not leading) and odd == even and mod == 0
                res = 0
                if leading:
                    res += _f(i - 1, mod * 10 % k, odd, even, True, False)
                lo = 1 if leading else 0
                hi = digi[i] if lim else 9
                for j in range(lo, hi + 1):
                    if j & 1:
                        res += _f(i - 1, (10 * mod + j) % k, odd + 1, even, False, lim and j == hi)
                    else:
                        res += _f(i - 1, (10 * mod + j) % k, odd, even + 1, False, lim and j == hi)
                return res
            return _f(len(digi) - 1, 0, 0, 0, True, True)
        return f(high) - f(low - 1)
