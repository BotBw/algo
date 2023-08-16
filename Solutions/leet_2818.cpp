// [>=x...x...>x]
class Solution {
public:
    typedef pair<int, int> pii;
    typedef long long ll;
    
    const int MOD = 1e9 + 7;
    ll pow(int x, ll y) {
        if (y == 0) return 1;
        ll half = pow(x, y >> 1);
        half = half * half % MOD;
        if ((y & 1) == 0) { 
            return half;
        } else { 
            return half * x % MOD;
        }
    }
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        int mx = 0;
        for(auto v: a) mx = max(mx, v);
        vector<int> omega(mx + 1);
        for(int x = 2; x <= mx; x++) {
            if(!omega[x]) {
                for(int y = x; y <= mx; y += x) omega[y] += 1;
            }
        }
        vector<int> left(n, -1), right(n, n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(s.size() && omega[a[s.top()]] < omega[a[i]]) {
                right[s.top()] = i;
                s.pop();
            }
            if(s.size()) left[i] = s.top();
            s.push(i);
        }
        priority_queue<pii> pq;
        for(int i = 0; i < n; i++){
            pq.push({a[i], i});
        }
        ll res = 1;
        // for(int i = 0; i < n; i++) cout << omega[a[i]] << " \n"[i == n - 1];
        // for(int i = 0; i < n; i++) cout << left[i] << " \n"[i == n - 1];
        // for(int i = 0; i < n; i++) cout << right[i] << " \n"[i == n - 1];

        while(pq.size()) {
            auto tmp = pq.top();
            pq.pop();
            int v = tmp.first, i = tmp.second;
            if (k > (ll)(right[i] - i) * (i - left[i])) {
                res *= pow(v, (ll)(right[i] - i) * (i - left[i]));
                res %= MOD;
                k -= (right[i] - i) * (i - left[i]);
            } else {
                res *= pow(v, k);
                res %= MOD;
                break;
            }
        }
        return res;
    }
};
