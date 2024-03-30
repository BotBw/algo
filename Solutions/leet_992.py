class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        
        def helper(nums, k):
            ans = 0
            l = 0
            cnt = defaultdict(int)
            for r in range(len(nums)):
                cnt[nums[r]] += 1
                while len(cnt) > k:
                    cnt[nums[l]] -= 1
                    if cnt[nums[l]] == 0:
                        del cnt[nums[l]]
                    l += 1
                ans += r - l + 1
            return ans
        
        return helper(nums, k) - helper(nums, k - 1)
