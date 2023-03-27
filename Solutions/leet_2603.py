class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        n = len(coins)
        g = [[] for _ in range(n)]
        deg = [0] * n
        res = n - 1

        def addEdge(u, v):
            g[u].append(v)
            g[v].append(u)
            deg[u] += 1
            deg[v] += 1

        for (u, v) in edges:
            addEdge(u, v)
        
        q = deque()
        for u in range(n):
            if deg[u] == 1 and coins[u] == 0:
                q.append(u)

        while q:
            u = q.popleft()
            res -= 1
            for v in g[u]:
                deg[v] -= 1
                if deg[v] == 1 and coins[v] == 0:
                    q.append(v)
                    
                    
        for u, (c, d) in enumerate(zip(coins, deg)):
            if d == 1 and c:
                res -= 1
                q.append(u)
        
        for u in q:
            for v in g[u]:
                deg[v] -= 1
                if deg[v] == 1:
                    res -= 1


        return max(res * 2, 0)
        

                    


