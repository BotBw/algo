class Solution {
public:
    int ans = 0;
    int minimumSum(int n, int k) {
        vector<int> cur;
        dfs(1, n, k, cur, 0);
        return ans;
    }
    
    bool dfs(int x, int n, int k, vector<int> &cur, int sum) {
        if(cur.size() == n) {
            ans = sum;
            return true;
        }
        bool ok = true;
        for(int i = 0; i < cur.size(); i++) {
            if(cur[i] + x == k) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cur.push_back(x);
            if(dfs(x + 1, n, k, cur, sum + x)) return true;
            cur.pop_back();
        }
        if(dfs(x + 1, n, k, cur, sum)) return true;
        return false;
    }
};
