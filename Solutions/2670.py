class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        diff = [0 for i in range(n)]
        for i in range(n):
            tmp = set()
            for j in range(0, i + 1):
                tmp.add(nums[j])
            a = len(tmp)
            tmp = set()
            for j in range(i + 1, n):
                tmp.add(nums[j])
            diff[i] = a - len(tmp)
        return diff
                