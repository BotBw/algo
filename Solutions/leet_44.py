class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        f = [[False for _ in range(n + 2)] for _ in range(m + 2)]
        f[-1][-1] = True
        for i in range(-1, m):
            for j in range(n):
                if p[j] == '*':
                    f[i][j] = (
                        f[i][j-1] # empty match
                        or f[i-1][j] # recursively match one char
                    )
                else:
                    f[i][j] = (
                        f[i-1][j-1] and (s[i] == p[j] or p[j] == '?')
                    )
        return f[m-1][n-1]
