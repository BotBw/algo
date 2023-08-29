class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        if sum(nums) < target: return -1
        
        cnt = Counter(nums)
        i = ans = summ = 0
        while 1 << i <= target:
            summ += cnt[1 << i] << i
            mask = (1 << (i + 1)) - 1
            i += 1
            if summ >= target & mask:
                continue
            ans += 1
            while cnt[1 << i] == 0:
                i += 1
                ans += 1
        return ans
