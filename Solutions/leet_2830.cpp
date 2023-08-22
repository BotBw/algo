class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [&](auto x, auto y) {
            return x[1] < y[1];
        });
        int mx = 0;
        for(auto &v: a) {
            v[0] += 1;
            v[1] += 1;
            mx = max(mx, v[1]);
        }
        vector<int> f(mx + 1);
        int i = 1, j = 0;
        for(; i <= mx && j < a.size(); i++) {
            if(i < a[j][1]) {
                f[i] = f[i - 1];
            } else {
                while(j < a.size() && i == a[j][1]) {
                    f[i] = max({f[i], f[i-1], f[a[j][0] - 1] + a[j][2]});
                    j++;
                }
            }
        }
        return f[mx];
    }
};
