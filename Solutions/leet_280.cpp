class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        l = len(nums)
        i, j = 0, l // 2
        k = 0
        tmp = nums[: l//2].copy()
        while i < l // 2 and j < l:
            if k % 2 == 0:
                v = tmp[i]
                i += 1
            else:
                v = nums[j]
                j += 1
            nums[k] = v
            k += 1
        if l % 2 == 1 and l >= 2:
            nums[-1], nums[-2] = nums[-2], nums[-1]
        
