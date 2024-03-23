class Solution:
    def numWays(self, n: int, k: int) -> int:
        f1 = k
        f2 = 0
        for i in range(1, n):
            pref2 = f2
            f2 = f1
            f1 = (f1 + pref2) * (k - 1)
        return f1 + f2
'''
f[i, j] j consecutive colors from [i - j + 1, j] j = 0, 1, 2
f[i, 1] = f[i - 1][1] * (k - 1)  + f[i - 1][2] * (k - 1)
f[i, 2] = f[i - 1][1] 
'''
