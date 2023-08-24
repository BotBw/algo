class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        n = len(str1)
        m = len(str2)
        j = 0
        for i in range(n):
            if j >= m:
                break
            c = ord(str1[i])
            if c == ord(str2[j]) or (c + 1 - ord('a')) % 26 + ord('a') == ord(str2[j]):
                j += 1
        return j == m
