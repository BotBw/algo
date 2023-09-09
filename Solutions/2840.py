class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(s1[1::2]) == Counter(s2[1::2])
        
class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        odd1 = defaultdict(int)
        odd2 = defaultdict(int)
        even1 = defaultdict(int)
        even2 = defaultdict(int)
        
        for i, c in enumerate(s1):
            if i % 2 == 1:
                odd1[c] += 1
            else:
                even1[c] += 1
        
        for i, c in enumerate(s2):
            if i % 2 == 1:
                odd2[c] += 1
            else:
                even2[c] += 1
                
        
        return odd1 == odd2 and even1 == even2
        
