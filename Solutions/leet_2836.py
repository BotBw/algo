class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        n = len(receiver)
        m = k.bit_length()
        pa = [[(p, p)] + [None] *  (m - 1) for p in receiver]
        
        for i in range(m - 1):
            for j in range(n):
                p, s = pa[j][i]
                pp, ss = pa[p][i]
                pa[j][i + 1] = (pp, s + ss)
        
        ans = 0
        
        for x in range(n):
            kk = k
            sum = x
            while kk:
                lowbit = kk & -kk
                kk -= lowbit
                x, s = pa[x][lowbit.bit_length() - 1]
                sum += s
            ans = max(ans, sum)

        return ans
