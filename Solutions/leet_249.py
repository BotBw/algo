class Solution:

    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        def modulo(dividend, divisor):
            result = dividend % divisor
            if result < 0:
                result += divisor
            return result

        di = defaultdict(partial(defaultdict, list))
        for s in strings:
            l = len(s)
            embed = ""
            for p, cur in zip(s, s[1:] + s[0]):
                embed += str(modulo(ord(cur) - ord(p), 26))
            di[l][embed].append(s)
        res = []
        for k1, v1 in di.items():
            for k2, v2 in v1.items():
                res.append(v2)
        return res
                
