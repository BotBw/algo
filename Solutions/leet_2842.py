class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
        MOD = 10 ** 9 + 7
        cnt = Counter(Counter(s).values())
        ans = 1
        for c, repeat in sorted(cnt.items(), reverse=True):
            if repeat >= k:
                return ans * pow(c, k, MOD) * comb(repeat, k) % MOD
            ans *= pow(c, repeat, MOD)
            ans %= MOD
            k -= repeat
        return 0
        
