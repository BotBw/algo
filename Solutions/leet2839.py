class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        odd1 = set()
        odd2 = set()
        even1 = set()
        even2 = set()
        
        for i, c in enumerate(s1):
            if i % 2 == 1:
                odd1.add(c)
            else:
                even1.add(c)
        
        for i, c in enumerate(s2):
            if i % 2 == 1:
                odd2.add(c)
            else:
                even2.add(c)
        
        return odd1 == odd2 and even1 == even2
        
