class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        dict = {}
        n = len(nums)
        l = r = 0
        sum = 0
        ans = 0
        while r < n:
            if nums[r] not in dict.keys():
                dict[nums[r]] = 0
            dict[nums[r]] += 1
            sum += nums[r]
            while r - l + 1 > k:
                dict[nums[l]] -= 1
                sum -= nums[l]
                if dict[nums[l]] == 0:
                    dict.pop(nums[l])
                l += 1
            if len(dict.keys()) >= m:
                # print(dict)
                ans = max(ans, sum)
            r += 1
        return ans
                
            
