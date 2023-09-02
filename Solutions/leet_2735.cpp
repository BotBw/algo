class Solution {
    /*
    class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        n = len(nums)
        inf = 10 ** 12
        ans = inf
        for i in range(0, n):
            val = [inf] * n
            q = deque()
            a = nums + nums
            a.pop()
            for j, v in enumerate(a):
                while q and nums[q[-1] % n] >= v: q.pop()
                q.append(j)
                while q and q[0] < j - i: q.popleft()
                val[j % n] = min(val[j % n], nums[q[0] % n])
            ans = min(ans, sum(val) + i * x)
        return ans
            
        */
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, int x) {
        const int inf = 0x3f3f3f3f;
        int n = nums.size();
        vector<int> a = nums;
        a.resize(n * 2 - 1);
        for(int i = 0 ; i < n - 1; i++) a[n + i] = nums[i];
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 0 ; i < n; i++) {
            vector<int> val(n, inf);
            deque<int> q;
            for(int j = 0; j < n * 2 - 1; j++) {
                while(q.size() && a[q.back()] >= a[j]) q.pop_back();
                q.push_back(j);
                while(q.size() && q.front() < j - i) q.pop_front();
                val[j % n] = min(val[j % n], a[q.front()]);
            }
            ll sum = 0;
            for(int j = 0; j < n ;j++) sum += val[j];
            ans = min(ans, (ll)sum + (ll)i * x);
        }
        return ans;
    }
};
