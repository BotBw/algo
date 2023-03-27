class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
      res = 0
      res += min(k, numOnes)
      k -= min(k, numOnes)
      if(k == 0):
        return res
      k -= min(k, numZeros)
      if(k == 0):
        return res
      res -= min(k, numNegOnes)
      return res
