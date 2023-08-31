class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        diff = [0] * (n + 1)
        for i in range(n):
            if i == 0: diff[0] = nums[0]
            else: diff[i] = nums[i] - nums[i - 1]
        cur = 0
        for i in range(n):
            cur += diff[i]
            if cur == 0: continue
            if i + k > n or cur < 0: return False 
            diff[i + k] += cur
            cur = 0
        return True
