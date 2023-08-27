from array import *
from ast import *
from bisect import *
from collections import *
from functools import *


MAX = 10 ** 5
MOD = 10 ** 9 + 7
omega = [0] * (MAX + 1)
for x in range(2, MAX + 1):
    if omega[x]:
        continue
    y = x
    while y < MAX + 1:
        omega[y] += 1
        y += x
        
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        s = []
        left = [-1] * len(nums)
        right = [len(nums)] * len(nums)
        # [>=, >]
        for i in range(len(nums)):
            while s and omega[nums[s[-1]]] < omega[nums[i]]:
                right[s.pop()] = i
            if s:
                left[i] = s[-1]
            s.append(i)

        ans = 1

        for i, v, l, r in sorted(zip(range(len(nums)), nums, left, right), key=lambda x: x[1], reverse=True):
            cnt = (i - l) * (r - i)
            if k >= cnt:
                k -= cnt
                ans *= pow(v, cnt, MOD)
                ans %= MOD
            else:
                ans *= pow(v, k, MOD)
                ans %= MOD
                break
        
        return ans