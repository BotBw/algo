class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        group = [[] for _ in range(k)]
        for v in range(len(arr)):
            group[v % k].append(arr[v])
        ans = 0
        print(group)
        for i in range(k):
            a = []
            for v in group[i]:
                id = bisect_right(a, v)
                if id < len(a):
                    a[id] = v
                else:
                    a.append(v)
            ans += len(group[i]) - len(a)

        return ans 
