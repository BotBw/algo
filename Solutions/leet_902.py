class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        digi = []
        while n:
            digi.append(n % 10)
            n //= 10
        @cache
        def f(i, leading, lim):
            if i == -1:
                return not leading
            res = 0
            if leading:
                res += f(i - 1, leading, False)
            low = 1 if leading else 0
            high = digi[i] if lim else 9
            for d in digits:
                if not (low <= int(d) <= high):
                    continue
                res += f(i - 1, False, lim and int(d) == high)
            return res
        return f(len(digi) - 1, True, True)
