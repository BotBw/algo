class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        n = len(nums)
        MOD = 10 ** 9 + 7
        @cache
        def dfs(mask, prev):
            if mask == 0: return 1
            res = 0
            for i, v in enumerate(nums):
                if mask >> i & 1 and (v % prev == 0 or prev % v == 0):
                    res += dfs(mask & ~(1 << i), v)
            return res
        mask = (1 << n) - 1
        return sum(dfs(mask & ~(1 << i), nums[i]) for i in range(n)) % MOD
