class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = []
        for v in nums:
            i = bisect_right(ans, v)
            if i == len(ans):
                ans.append(v)
            else:
                ans[i] = v
        return len(nums) - len(ans)
            
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        f = [0] * 4
        for x in nums:
            for j in range(3, 0, -1):
                f[j] = min(f[k] for k in range(1, j + 1)) + (j != x)
        return min(f[1:])
