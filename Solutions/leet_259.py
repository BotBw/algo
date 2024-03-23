class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                k = bisect.bisect_right(nums, target - nums[i] - nums[j] - 1) - 1 # ak <= t - ai - aj - 1
                res += max(0, k - j)
        return res
