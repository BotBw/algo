class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        arr = []
        for l, r, h in buildings:
            arr.append([l, h])
            arr.append([r, -h])
        arr.sort(key=lambda x: x[0])
        query = [0]
        cur = 0
        res = []
        for i, (x, h) in enumerate(arr):
            if h > 0:
                query.append(h)
            else:
                query.remove(-h)
            if i + 1 < len(arr) and x == arr[i + 1][0]: continue
            if (mx := max(query)) != cur:
                cur = mx
                res.append([x, mx])
        return res
