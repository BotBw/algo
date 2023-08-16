class Solution {
public:
    const int inf = INT_MAX;
    int minAbsoluteDifference(vector<int>& a, int x) {
        set<int> se{-inf/2, inf};
        int n = a.size();
        int mn = inf;
        for(int i = x; i < n; i++) {
            se.insert(a[i-x]);
            auto it = se.lower_bound(a[i]);
            mn = min(mn, abs(*it - a[i]));
            it--;
            mn = min(mn, abs(*it - a[i]));
        }
        return mn;
    }
};
